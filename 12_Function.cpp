#include<iostream>

using namespace std;

// 코드블럭 외부에 변수를 선언하게 되면 전역변수가 된다. 전역변수는 이 변수를
// 선언한 아래의 모든 부분에서 공유해서 사용이 가능하다.
// 전역변수는 소속된 코드블럭이 없으므로 프로그램이 종료될때까지 메모리에서 존재하게
// 되고 프로그램이 종료될 때 메모리에서 해제가 된다.
int g_iNum = 123;

/*
함수 : 기능을 만들어준다. 일종의 사용할 수 있는 부품을 만들어준다고 볼 수 있다.
특정 상황에 동작하는 코드 집합을 만들어내는 것이다.
형태 : 반환타입 함수명(인자) {} 의 형태로 구성이 된다.
반환타입 : 이 함수가 기능을 수행하고 기능의 결과를 반환해야 할 경우 지정한다.
정수를 반환할때는 정수타입, 실수를 반환할때는 실수타입으로 지정한다.
그 외 타입이라면 해당타입을 지정해주면 된다.
함수명 : 함수의 이름을 의미한다. 함수명은 가급적이면 이 함수가 하는 역할을
정확하게 표시해 주는 것이 코드 가독성에 좋다.
인자 : 해당 함수를 사용할때 넘겨줄 값이 있을 경우 인자를 활용 한다. 인자는 있을수고
있고 없을수도 있다.

해당 함수를 호출하면 코드블럭 안의 코드가 동작이 된다.
*/
// 아래 함수처럼 결과를 반환해주는 함수 현태를 Call by value라고 한다.
int Sum(int a, int b)
{
	// return 키워드를 이용해서 이 함수의 반환타입에 맞는 값을 반환해야 한다.
	return a + b;
}

// 함수는 단순히 만들어놓기만 해서는 아무런 동작도 하지 않는다. 함수의 기능을
// 동작시키기 위해서는 반드시 main 함수 안에서 해당 함수를 호출해 주어야 한다.
void OutputText()
{
	cout << "OutputText Function!" << endl;
}

// 아래 함수처럼 인자를 넘겨받게 될 경우 이 인자는 이 함수 코드블럭의 지역에
// 속해있다고 판단한다. 즉, 이 함수의 비역변수가 되고 stack에 할당된다.
// 할당된 지역변수는 해당 지역변수가 소속된 코드블럭이 닫히게 되면 메모리에서
// 해제된다.
void OutputNumber(int iNumber)
{
	cout << "Number : " << iNumber << endl;
}

void ChangeNumber(int iNumber)
{
	iNumber = 9999;
	g_iNum = 456;
}

// 함수의 디폴트인자 : 인자는 기본적으로 값을 넘겨받게 설계되어 있다. 그런데 인자에
// 기본값을 대입해두면 인자를 넘겨주지 않을 경우 기본 설정한 값이 되고 인자를 넘겨줄
// 경우 넘겨받은 값으로 인자를 설정하는 기능이다.
// 디폴트인자는 가장 오른쪽부터 지정해 주어야한다
void Output(int iNum1, int iNum2 = 10)
{
	cout << iNum1 << endl;
	cout << iNum2 << endl;
}

void Output(float iNum1)
{
}

/*
함수의 오버로딩 : 같은 이름의 함수지만 기능이 다르던다 인자가 다른 함수를
말한다.
오버로딩 조건 : 함수 이름이 무조건 같아야 한다. 단, 인자의 개수 혹은 타입이
달라야 오버로딩이 성립이 된다. 반환타입은 오버로딩에 영향을 주지 않는다.
*/

// 아래 함수는 결과값을 인자로 받아와서 결과를 반환해주었다. 이런 형태의 함수를
// Call by Address라고 한다.
void ChangeNumber(int* pNumber)
{
	*pNumber = 2939;
}

int main()
{
	// 함수를 호출할때는 함수명(인자로 넘겨줄 값); 의 형태로 호출을 하게 된다.
	// 아래처럼 호출하면 a에 10, b에 20이 전달되어 두 값을 더한 30이 반환된다.
	cout << Sum(10, 20) << endl;
	cout << Sum(102, 304) << endl;

	OutputText();
	OutputNumber(1234);

	// 아래처럼 특정 코드블럭 안에서 선언되는 변수를 지역변수라고 한다.
	// 지역변수는 메모리 영역중 stack에 할당된다.
	int iNumber = 0;

	ChangeNumber(iNumber);
	ChangeNumber(&iNumber);

	cout << iNumber << endl;
	cout << g_iNum << endl;

	Output(10, 30);
	
	{
		int iNum1 = 1234;
	}

	// iNum1은 위의 코드블럭 안에 존재하는 변수이므로 저 코드블럭 안에서만 사용
	// 할 수 있다.
	// cout << iNum1 << endl;

	return 0;
}