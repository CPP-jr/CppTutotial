#include<iostream>
#include<time.h>

using namespace std;

/*
숙제 : 야구게임 만들기
1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 순자는 중복되어서는 안 된다.
3개의 숫자는 * * *의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
사용자는 이 3개의 숫자를 맞출 때까지 계속 해서 3개씩 숫자를 입력한다.
만약 맞춰야할 숫자가 7 3 8일 경우 사용자는 3개의 숫자를 계속 입력한다.
입력 : 1 2 4 를 입력했을 경우 1 2 4는 맞춰야할 숫자중 아무것도 없으므로
Out을 출력한다.

입력 : 7 5 9를 입력했을 경우 7은 맞춰야할 숫자중 있고 위치도 같으므로
strike이다. 5 9는 없으므로 출력은 1strike 0ball을 출력한다.

입력 : 7 8 6을 입력했을 경우 7은 1strike 8은 숫자는 있지만 위치가 자르므로 ball이 된다.
1strike 1ball을 출력한다.

이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게
입력하면 게임이 종료된다. 만약 입력받은 숫자 3개중 한개라도 0이 있을 경우 게임을 종료한다.
*/

int main()
{

	/*
	구구단을 2단부터 9단까지 출력한다.
	*/
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}

	cout << endl;

	/*
	2단 3단 4단
	5단 6단 7단
	8단 9단 10단
	*/

	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i + 1 << " * " << j << " = " << (i + 1) * j << "\t";
			cout << i + 2 << " * " << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}


	/*
	*
	**
	***
	****
	*****
	*/

	for (int i = 0; i < 5; ++i) // 세로줄
	{
		for (int j = 0; j < i + 1; ++j) // 가로줄
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;


	/*
	*****
	****
	***
	**
	*
	*/

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	/*
	   *
	  ***
	 *****
	*******
	*/
	// 공백 : 3, 2, 1, 0		별 : 1, 3, 5, 7
	for (int i = 0; i < 4; ++i)
	{
		// 공백을 출력하기 위한 for문
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";
		}

		// *을 출력하기 위한 for문
		for (int j = 0; j < 2 * i + 1; ++j)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	/*
	   *
	  ***
	 *****
	*******
	 *****
	  ***
	   *
	*/
	int iLine = 7;
	int iCount = 0;

	for (int i = 0; i < iLine; ++i)
	{
		// 공백 : 3, 2, 1, 0, 1, 2, 3
		// 별 : 1, 3, 5, 7, 5, 3, 1

		iCount = i;

		// i값이 7줄 기눙 4, 5, 6 즉 밑의 삼각형을 구성할 때만 if문에 들어가게 된다.
		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
		}

		// i값이 0, 1, 2, 3일 때는 iCount는 i값을 그대로 대입된다.
		// i값이 4, 5, 6일 때 iCount는 2, 1, 0이 된다.
		// 즉, 최종 i값은 0, 1, 2, 3, 2, 1, 0으로 돌아가게 된다.

		for (int j = 0; j < iLine/2 - iCount; ++j)
		{
			cout << " ";
		}

		for (int j = 0; j < iCount * 2 + 1; ++j)
		{
			cout << "*";
		}
		
		cout << endl;
	}

	/*
	do while 문 : 반복문의 한 종류이다.
	형태 : do {}while(조건식); 의 형태로 구성된다.
	while문은 처음 진입부터 조건식을 체크하지만 do while은 처음 한번은 무조건 동작이 되고
	그 후에 조건식을 체크해서 true일 경우 동작되는 반복문이다.
	*/

	int iNumber = 0;
	int iNumber1 = 0, iNumberr2 = 0, iNumber3 = 0;

	do
	{
		// cout << iNumber << endl;
	} while (iNumber > 0);

	/*
	배열 : 여러개의 변수를 한번에 생성해줄 수 있는 기능이다.
	형태 : 변수타입 배열명[개수]; 의 형태로 선언할 수 있다.
	배열의 특징 : 배열은 연속된 메모리 블럭에 공간이 할당된다
	*/

	// 배열뿐만 아니라 일반 변수들도 선언을 하고 값을 초기화하지 않을 경우 쓰레기값이
	// 들어가게 된다.
	// int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 0 ~ 4번 까지는 1, 2, 3, 4, 5 의 값이 들어가게 되고 나머지는 모두 0으로 초기화횐다.
	// int iArray[10] = { 1, 2, 3, 4, 5 };
	int iArray[10] = {};
	
	iArray[1] = 1234;

	for (int i = 0; i < 10; ++i)
	{
		cout << iArray[i] << endl;
	}

	// cout << iArray[5] << endl;

	/*
	배열 개수를 2개 지정하면 이차원 배열이 된다. 3개 지정하면 3차원 배열이 된다.
	2차원 배열의 재수를 앞의수*뒤의수 만큼 처리가 된다. 아래는 10 * 10 개의 배열이
	생성된느 것이다.
	*/

	int iArray2[10][10] = { { 1, 2, 3 }, { 4, 5, 6 } };
	// int iArr[99999999999];

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << iArray2[i][j] << "\t";
		}

		cout << endl;
	}

	system("cls");

	srand((unsigned int)time(0));

	// Lotto program
	int iLotto[45] = {};

	// 1 ~ 45까지의 숫자를 차례대로 넣어준다.
	for (int i = 0; i < 45; i++)
	{
		iLotto[i] = i + 1;
	}

	// Swap 알고리즘
	/*int iNum1 = 1, iNum2 = 2, iNum3 = 3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;*/

	// Shuffle
	int iTemp, idx1, idx2;
	// 100번정도 골고루 섞어준다.
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << "\t";
	}

	cout << "보너스 번호 : " << iLotto[6] << endl;
	

	return 0;
}