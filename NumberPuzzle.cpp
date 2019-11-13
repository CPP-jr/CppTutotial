#include<iostream>
#include<time.h>

// console input output 헤더파일이다. 콘솔창에서 입출력 하는 기능들을
// 제공해주는 헤더파일이다.
#include<conio.h>

/*
숙제 : 숫자빙고게임을 만들어보자.
1 ~ 25 까지의 숫자가 있고 이 숫자를 공고루 섞어서 5 x 5 로 출력한다.
플레리어의 숫자를 입력받는다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
0을 입력하면 게임을 종료한다.

숫자를 입려받았으면 숫자목록중 입력받을 숫자를 찾아서 *로 만들어분다.
숫자를 *로 만든 후에 빙고 줄 수를 체크한다. 5 x 5 이기 때문에 가로 5줄 세로 5줄
대각선 2줄이 나올 수 있다. 빙고줄이 볓줄인지를 체크해서 화면에 보여준다.
5줄 이상일 경우 게임을 종료한다.
*/

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을
	// 사용할건데 INT_MAX라는 값을 사용할것이다. INT_MAX는 이미 정의되어있는 값으로
	// int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;

	// 별이 있는 위치를 저장할 변수를 만들어준다.
	int iStarIndex = 24;

	// 마지막 공배개을 제외하고 1 ~ 24 까지의 숫자만 섞어준다. 즉, 인덱스는 0 ~ 23번
	// 인덱스 까지만 섞어준다.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");
		// i for문이 세로줄을 의미한다.
		for (int i = 0; i < 5; ++i)
		{
			// j for문이 가로 칸을 의미한다.
			for (int j = 0; j < 5; ++j)
			{
				// i가 0일 때 j는 0 ~ 4까지 반복한다. 이 경우 0 * 5 + (0 ~ 4)를 더하게돼서
				// 인덱스는 0, 1, 2, 3, 4 가 나오게 된다.
				// i가 1일 때 j는 0 ~ 4 까지 반복한다. 이경우 1 * 5 + (0 ~ 4)를 더하게돼서
				// 인덱스는 5, 6, 7, 8, 9 가 나오게 된다.
				// i가 2일 때 j는 0 ~ 4 까지 반복한다. 이경우 2 * 5 + (0 ~ 4)를 더하게돼서
				// 인덱스는 10, 11, 12, 13, 14 가 나오게 된다.
				// i가 3일 때 j는 0 ~ 4 까지 반복한다. 이경우 3 * 5 + (0 ~ 4)를 더하게돼서
				// 인덱스는 15, 16, 17, 18, 19 가 나오게 된다.
				// i가 4일 때 j는 0 ~ 4 까지 반복한다. 이경우 4 * 5 + (0 ~ 4)를 더하게돼서
				// 인덱스는 20, 21, 22, 23, 24 가 나오게 된다.
				// 줄번호 * 가로개수 + 칸번호

				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		// true로 주어서 먼저 모두 맞췄다 라고 가정해둔다.
		bool	bWin = true;

		// 퍼즐을 맞추었는지 체크한다.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		cout << "WSAD : 이동. Q : 종료.";
		// _getch() 함수는 문자 1개를 입력받는 함수이다. 이 함수는 Enter를 치지 않더라고
		// 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		char	cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			// 가장 윗줄일 때는 w를 눌러도 위로 올라가서는 안 된다.
			if (iStarIndex > 4)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸위의 인덱스로 만들어준다.
				iStarIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			// 가장 아래줄이 아닐 경우 움직인다.
			if (iStarIndex < 20)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				--iStarIndex;
			}
			break;
		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				++iStarIndex;
			}
			break;
		}
	}

	cout << endl << "게임을 종료합니다." << endl;

	return 0;
}