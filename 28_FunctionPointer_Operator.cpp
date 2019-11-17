#include<iostream>
#include<functional>

using namespace std;

/*
�Լ������� : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� �ִ�.
	�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.
�Լ������� ������ : ��ȯŸ�� (*�����ͺ�����)(����Ÿ��); �� ���·� ������ �ȴ�.
*/

int Sum(int a, int b)
{
	return a + b;
}

int OutSum(int a, int b)
{
	cout << a - b << endl;
	return a - b;
}

float TestFunc(float a)
{
	cout << a << endl;
	return a;
}

void Output()
{
	cout << "Output Function" << endl;
}

class CHanzo
{
public:
	CHanzo()
	{
	}

	~CHanzo()
	{
	}

public:
	int		m_iText;

public:
	void Output()
	{
		cout << "Hanzo" << endl;
		// this-> �� ������ �� �ִ�.
		cout << "Test : " << this->m_iText << endl;
	}
};

typedef struct _tagPoint
{
	int	x;
	int	y;

	_tagPoint() :
		x(0),
		y(0)
	{
	}

	_tagPoint(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}

	_tagPoint(const _tagPoint& pt)
	{
		// ���� ���縦 �Ѵ�. �̷��� ���� ��� this�� �ڱ��ڽ��� �������̰�
		// *�� �ٿ��� �ڱ��ڽ��� �������Ͽ� ��� �����͸� �����ϰ� �Ѵ�.
		*this = pt;
	}

	_tagPoint operator + (const _tagPoint& pt)
	{
		_tagPoint	result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	_tagPoint operator +(int a)
	{
		_tagPoint	pt;
		pt.x = x + a;
		pt.y = y + a;
		return pt;
	}

	void operator +=(int a)
	{
		x += a;
		y += a;
	}

	void operator ++()
	{
		x++;
		y++;
	}

	void operator --()
	{
		x--;
		y--;
	}

	void operator << (const _tagPoint& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	void operator >>(_tagPoint& pt)
	{
		pt.x = x;
		pt.y = y;
	}

}POINT, * PPOINT;

int main()
{
	int(*pFunc)(int, int) = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;

	pFunc(10, 20);

	// pFunc = Output();
	void(*pFunc1)() = Output;

	pFunc1();

	CHanzo hanzo1, hanzo2;

	hanzo1.m_iText = 100;
	hanzo2.m_iText = 200;

	// this ������ : Ŭ���� �ȿ��� this�� ����Ұ�� �ش� ��ü�� �޸�
	// �ּҰ� �ȴ�. �� �ڱ��ڽ��� �������̴�.
	// ����Լ��� ȣ���Ҷ� this�� ȣ���ڷ� �����Ѵ�.
	hanzo1.Output();
	hanzo2.Output();

	// ����Լ������� ����� �����ͺ��� �̸� �տ� Ŭ������:: �� �ٿ��ش�.
	void(CHanzo:: * pFunc2)() = &CHanzo::Output;

	//(*pFunc2)();

	//hanzo1.(*pFunc2());
	(hanzo1.*pFunc2)();

	/*
	function ����� C++11 ���� ������ ���ִ� ����̴�. �� ����� �Լ������͸�
	����, ��� ������ �ʰ� ���� �ּҸ� �����ؼ� ȣ������ �� �ֵ��� ������ִ�
	����̴�.
	������ : function<��ȯŸ��(����Ÿ��)> ������;
	*/
	function<void()>	func;
	function<void()>	func1;

	// bind�� �̿��ؼ� �Լ��� �����ش�.
	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo2);

	cout << endl << "=========== Functional ===========" << endl;
	func();
	func1();

	function<int(int, int)>	func3;
	function<float(float)>	func4;

	// �Լ��� ���ڰ� ���� ��� placeholders �� �̿��ؼ� ������ ������
	// ������ �� �ִ�. �Ʒ�ó�� 2, 1�� �־��ָ� ���ڰ� ���� �ٲ�� �ȴ�.
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	// ������ 2, 1�� �ٲ�Z���Ƿ� 10�� b�� 20�� a�� ���� �ȴ�.
	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	func4(3.14);

	cout << endl << "============== Point ==============" << endl;
	POINT	pt1(10, 20), pt2(30, 40), pt3;

	// POINT ����ü�� +�����ڰ� operator�� ������ �Ǿ��ִ�.
	// �׷��� + ������ �����ϰ� �ǰ� pt1�� + ������ �Լ��� ȣ�����ִ�
	// �����̴�. pt2�� ���ڷ� �Ѱ��ش�.
	pt3 = pt1 + pt2;

	pt3 << pt1;

	pt2 >> pt3;

	pt3 = pt1 + 1000;

	pt3 += 2000;

	++pt3;

	--pt3;

	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;

	return 0;
}