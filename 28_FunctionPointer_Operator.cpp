#include<iostream>
#include<functional>

using namespace std;

/*
함수포인터 : 함수의 메모리 주소를 저장하기 위한 포인터 변수를 선언할 수 있다.
	전역함수의 경우 함수명이 곧 함수의 메모리 주소이다.
함수포인터 선언방법 : 반환타입 (*포인터변수명)(인자타입); 의 형태로 구성이 된다.
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
		// this-> 는 생략할 수 있다.
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
		// 얕은 복사를 한다. 이렇게 해줄 경우 this는 자기자신의 포인터이고
		// *을 붙여서 자기자신을 역참조하여 모든 데이터를 복사하게 한다.
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

	// this 포인터 : 클래스 안에서 this를 사용할경우 해당 객체의 메모리
	// 주소가 된다. 즉 자기자신의 포인터이다.
	// 멤버함수를 호출할때 this를 호출자로 세팅한다.
	hanzo1.Output();
	hanzo2.Output();

	// 멤버함수포인터 선언시 포인터변수 이름 앞에 클래스명:: 을 붙여준다.
	void(CHanzo:: * pFunc2)() = &CHanzo::Output;

	//(*pFunc2)();

	//hanzo1.(*pFunc2());
	(hanzo1.*pFunc2)();

	/*
	function 기능은 C++11 부터 지원을 해주는 기능이다. 이 기능은 함수포인터를
	전역, 멤버 가리지 않고 쉽게 주소를 저장해서 호출해줄 수 있도록 만들어주는
	기능이다.
	선언방법 : function<반환타입(인자타입)> 변수명;
	*/
	function<void()>	func;
	function<void()>	func1;

	// bind를 이용해서 함수를 묶어준다.
	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo2);

	cout << endl << "=========== Functional ===========" << endl;
	func();
	func1();

	function<int(int, int)>	func3;
	function<float(float)>	func4;

	// 함수에 인자가 있을 경우 placeholders 를 이용해서 인자의 순서를
	// 정의할 수 있다. 아래처럼 2, 1로 넣어주면 인자가 서로 바뀌게 된다.
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	// 위에서 2, 1로 바꿔줫으므로 10은 b에 20은 a에 들어가게 된다.
	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	func4(3.14);

	cout << endl << "============== Point ==============" << endl;
	POINT	pt1(10, 20), pt2(30, 40), pt3;

	// POINT 구조체는 +연산자가 operator로 재정의 되어있다.
	// 그래서 + 연산이 가능하게 되고 pt1의 + 연산자 함수를 호출해주는
	// 개념이다. pt2를 인자로 넘겨준다.
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