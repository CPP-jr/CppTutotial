#include <iostream>
#include<time.h>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};


int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	// 1 ~ 25 숫자 넣어준다.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI 숫자도 섞어준다.
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	// AI 난이도를 선택한다.
	while (true)
	{
		system("cls");
		cout << "1. EASY" << endl;
		cout << "2. HARD" << endl;
		cout << "AI 난이도를 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}


	// AI Easy 모드는 현재 AI 숫자목록중 *로 바뀌지 않은 숫자 목록을 만들어서 그 목록중 임의로 하나를 선택한다.
	// 선택 안 된 목록 배열을 만들어준다.
	int iNoneSelect[25] = {};
	// 선택 안 된 숫자의 개수를 저장한다.
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");



		cout << "============== Player ==============" << endl;

		// 숫자를 5 x 5로 출력
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";

			}

			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl;

		// AI 빙고판 출력
		cout << endl;
		cout << "================ AI ================" << endl;

		switch (iAIMode)
		{
		case AM_EASY:
			cout << "EASY" << endl;
			break;
		case AM_HARD:
			cout << "HARD" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iAINumber[i * 5 + j] << "\t";

			}

			cout << endl;
		}

		cout << "AI Bingo Line : " << iAIBingo << endl << endl;

		// 줄 수가 5 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
		{
			cout << "Player 승리" << endl;
			break;
		}

		else if (iAIBingo >= 5)
		{
			cout << "AI 승리" << endl;
			break;
		}

		cout << "숫자를 입력하세요(종료:0) >> ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput>25)
			continue;

		// 중복체크
		bool bAcc = true;

		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i])
			{
				bAcc = false;

				iNumber[i] = INT_MAX;

				break;
			}
		}

		if (bAcc)
			continue;

		// 중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// AI가 선택을 한다. AI가 선택하는 것은 AI 난이도에 따라 달라진다.
		switch (iAIMode)
		{
		case AM_EASY:
			// 선택되지 않은 숫자목록을 만들어준다.
			// 선택되지 않은 숫자 개수는 목록을 만들 때 카운팅해준다.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i)
			{
				// 현재 숫자가 *이 아닐 경우
				if (iAINumber[i] != INT_MAX)
				{
					// *이 아닌 수자일 경우 iNoneSelectCount를 인덱스로 활용한다.
					// 선택되지 않은 목록에 추가할 때마다 객수를 1씩 증가시켜서 선택되지 않은 총 숫자를 구한다.
					// 그런데 0부터 카운트가 시작이므로 0번에 넣고 ++해서 1개 추가되었다고 해준다.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			// for문을 빠져나오게 되면 선택 안 된 목록이 만들어지고 선택 안 된 목록의 개수가 만들어진다.
			// 선택 안 된 목록의 숫자중 랜덤한 하나의 숫자를 얻어오기 위해 인덱스를 랜덤하게 구해준다.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;

		case AM_HARD:
			// 하드 난이도는 현재 숫자중 빙고 줄 완성 가능성이 가장 높은 줄을 찾아서
			// 그 줄에 있는 숫자중 하나를 *로 만들어준다.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// 가로, 세로 라인 중 가장 *이 많은 줄을 찾아낸다.
			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				// 별이 5개 미만이어야 빙고 줄이 아니고
				// 기존에 가장 많은 라인의 별보다 커야 많은 라인이므로 라인을 교체해주고 저장된 별 수를 교체한다.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// 여기는 가로 라인중 가잘 별이 많은 라인을 체크하는 곳인다.
					// 가로 라인은 0 ~ 4로 의미를 부여했다.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// 가로 라인중 가발 별이 많은 라인은 이미 구했다.
			// 이 값과 새로 라인들을 비교하여 별이 가장 많은 라인을 구한다.
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// 세로라인은 5 ~ 9로 의미를 부여했다.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// 왼쪽 -> 오른쪽 대각선 체크
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			// 오른쪽 -> 왼쪽 대각선 체크
			iStarCount = 0;
			for (int i = 4; i <= 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			// 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가 저장되었다.
			// 그 줄에 있는 *이 아닌 숫자중 하나를 선택하게 한다.
			if (iLine <= LN_H5)
			{
				// 가로줄일 경우 iLine이 0 ~ 4 사이의 값이다.
				for (int i = 0; i < 5; ++i)
				{
					// 현재 줄에서 *이 아닌 숫자를 찾아낸다.
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5)
			{
				// 세로줄일 경우 iLine이 5 ~ 9 사이의 값이다.
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 4; i <= 20; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}


			break;
		}

		// AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다.
		// 이 값과 세로 라인들을 비교하여 별이 가잘 많은 라인을 구한다.


		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// AI 숫자를 바꿔준다.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}


		// 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때마다 처음부터 새로 카운트할 것이다
		// 그러므로 iBingo 변수를 0으로 매번 초기화하고 새롭게 줄 수를 구해주도록한다.
		iBingo = 0;
		iAIBingo = 0;

		// 가로, 세로 줄 수를 구해준다.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			// 한 줄을 체크하기 전에 먼저 별 갯수를 0으로 초기화한다.
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				// 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				// 세로 별 개수를 구해준다.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				// AI 줄 체크
				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;

				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}

			// j for문을 빠져나오고 나면 현재 줄의 가로 별 객수가 몇개인지 iStar1 변수에 들어가게 된다.
			// iStar1 값이 5이면 한 줄이 모두 *이라는 의미이므로 빙고 줄 카운트를 추가해준다.
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			// AI 빙고 카운트

			if (iAIStar1 == 5)
				++iAIBingo;

			if (iAIStar2 == 5)
				++iAIBingo;

		}

		// 왼쪽 상단 -> 오른쪽 하단 대각선  체크
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAIStar1 == 5)
			++iAIBingo;

		// 오른쪽 상단 -> 왼쪽 하단 대각선 체크
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAIStar1 == 5)
			++iBingo;
	}

	return 0;
}
