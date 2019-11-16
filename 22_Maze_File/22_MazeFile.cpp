#include<iostream>
#include<conio.h>
#include<time.h>

using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 파워아이템
6 : 벽밀기 아이템
7 : 투명아이템
*/

struct _tagPoint
{
	int x;
	int y;
};

// typedef : 타입 재정의
typedef _tagPoint	POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint	tPos;
	bool		bWallPush;
	bool		bPushOnOff;
	bool		bTransparency;
	int			iBombPower;
}PLAYER, * PPLAYER;

void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos)
{
	// MazeList.txt 파일을 읽어와서 미로 목록ㅇ르 만든다.
	FILE*	pFile = NULL;

	fopen_s(&pFile, "MazeList.txt", "rt");

	char**	pMazeList = NULL;

	if (pFile)
	{
		char	cCount;

		fread(&cCount, 1, 1, pFile);

		int iMazeCount = atoi(&cCount);

		fread(&cCount, 1, 1, pFile);

		// char* 배열을 미로 개수만큼 할당한다.
		pMazeList = new char* [iMazeCount];

		for (int i = 0; i < iMazeCount; ++i)
		{
			int iNameCount = 0;

			// 현재 미로의 파일 이름을 저장할 배열을 256대로 할당
			// 해둔다. 미리 넉넉하게 할당해둔 것이다.
			pMazeList[i] = new char[256];

			while (true)
			{

				fread(&cCount, 1, 1, pFile);

				if (cCount != '\n')
				{
					pMazeList[i][iNameCount] = cCount;
					++iNameCount;
				}

				else
					break;				
			}

			// 파일 이름을 모두 읽었다면 문자열의 마지막에 0을
			// 넣어서 이 문자열의 끝은 알려준다.
			pMazeList[i][iNameCount] = 0;

			// cout << pMazeList[i] << endl;
		}

		fclose(pFile);

		// 읽을 파일 목록이 만들어졌으므로 각 파일중 하나를 선택해서
		// 미로를 읽어와서 설정한다.

		for (int i = 0; i < iMazeCount; ++i)
		{
			cout << i + 1 << ". " << pMazeList[i] << endl;
		}

		cout << "미로를 선택하세요 : ";
		int iSelect;
		cin >> iSelect;

		fopen_s(&pFile, pMazeList[iSelect - 1], "rt");

		if (pFile)
		{
			// 미로의 세로 줄만큼 반복하며 각 줄 별로 읽어온다.
			for (int i = 0; i < 20; ++i)
			{
				fread(Maze[i], 1, 20, pFile);

				// 현재 줄의 미로를 검사하여 시작점, 혹은
				// 도착점이 있는지는 판단한다.
				for (int j = 0; j < 20; ++j)
				{
					// 시작점일 경우
					if (Maze[i][j] == '2')
					{
						pStartPos->x = j;
						pStartPos->y = i;

						pPlayer->tPos = *pStartPos;
					}

					// 도착점일 경우
					else if (Maze[i][j] == '3')
					{
						pEndPos->x = j;
						pEndPos->y = i;
					}
				}

				// 개행문자를 읽어온다.
				fread(&cCount, 1, 1, pFile);
			}

			fclose(pFile);
		}
	}

	/*
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	pPlayer->tPos = *pStartPos;


	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "01111111111110000000");
	strcpy_s(Maze[2],  "01000100000011111100");
	strcpy_s(Maze[3],  "01000100000000000100");
	strcpy_s(Maze[4],  "01000111110001111100");
	strcpy_s(Maze[5],  "01000000001111000000");
	strcpy_s(Maze[6],  "01000000001000000000");
	strcpy_s(Maze[7],  "01100000001111111000");
	strcpy_s(Maze[8],  "00101110000000001000");
	strcpy_s(Maze[9],  "01111011111111111000");
	strcpy_s(Maze[10], "01000000000000001000");
	strcpy_s(Maze[11], "01111100111111100000");
	strcpy_s(Maze[12], "00000111100000111110");
	strcpy_s(Maze[13], "01111100000000000010");
	strcpy_s(Maze[14], "01000000001111111110");
	strcpy_s(Maze[15], "01111110011000000000");
	strcpy_s(Maze[16], "00000010010000000000");
	strcpy_s(Maze[17], "01111110011111000000");
	strcpy_s(Maze[18], "01000000000001100000");
	strcpy_s(Maze[19], "11000000000000111113");
	*/
}

void Output(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (Maze[i][j] == '4')
				cout << "б";

			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i) // j가 가로, i가 세로
				cout << "＠";

			else if (Maze[i][j] == '0')
				cout << "■";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "≠";

			else if (Maze[i][j] == '3')
				cout << "Д";

			else if (Maze[i][j] == '5')
				cout << "♨";

			else if (Maze[i][j] == '6')
				cout << "☞";

			else if (Maze[i][j] == '7')
				cout << "▒";
		}

		cout << endl;
	}

	cout << endl << "BOMB POWER : " << pPlayer->iBombPower << endl;
	cout << "WALKING THRU WALLS: "; // 벽통과
	if (pPlayer->bTransparency)
		cout << "ON.   ";

	else
		cout << "OFF.   ";

	cout << "PUSH : "; // 벽밀기
	if (pPlayer->bWallPush)
		if (pPlayer->bWallPush)
		{
			cout << "AVAILABILITY / ";

			if (pPlayer->bPushOnOff)
				cout << "ON" << endl;

			else
				cout << "OFF" << endl;
		}

		else
			cout << "OFF" << endl;
}

bool AddItem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{
		if (pPlayer->iBombPower < 5)
			++pPlayer->iBombPower;

		return true;
	}

	else if (cItemType == '6')
	{
		pPlayer->bWallPush = true;
		pPlayer->bPushOnOff = true;
		return true;
	}

	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}

	return false;
}

void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y - 1 >= 0)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}

		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우 
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0')
		{
			// 벽 밀기가 ON 상태일 경우 
			if (pPlayer->bPushOnOff)
			{
				// 위의 윗칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y - 2 >= 0)
				{
					// 위의 윗칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다.
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.y;
					}

					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1')
					{
						// 위의 윗칸을 벽으로 하고
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						// 윗칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1';
						// 플레이어를 이동시킨다.
						--pPlayer->tPos.y;
					}
				}

				else if (pPlayer->bTransparency)
					--pPlayer->tPos.y;
			}

			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 20)
	{
		// 벽인지 체크
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}

		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우 
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0')
		{
			// 벽 밀기가 ON 상태일 경우 
			if (pPlayer->bPushOnOff)
			{
				// 위의 윗칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y + 2 < 20)
				{
					// 위의 윗칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다.
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.y;
					}

					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1')
					{
						// 위의 윗칸을 벽으로 하고
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						// 윗칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1';
						// 플레이어를 이동시킨다.
						++pPlayer->tPos.y;
					}
				}

				else if (pPlayer->bTransparency)
					++pPlayer->tPos.y;
			}

			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0)
	{
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}

		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우 
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0')
		{
			// 벽 밀기가 ON 상태일 경우 
			if (pPlayer->bPushOnOff)
			{
				// 위의 윗칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x - 2 >= 0)
				{
					// 위의 윗칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다.
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.x;
					}

					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1')
					{
						// 위의 윗칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						// 윗칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1';
						// 플레이어를 이동시킨다.
						--pPlayer->tPos.x;
					}
				}

				else if (pPlayer->bTransparency)
					--pPlayer->tPos.x;
			}

			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20)
	{
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}

		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우 
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0')
		{
			// 벽 밀기가 ON 상태일 경우 
			if (pPlayer->bPushOnOff)
			{
				// 위의 윗칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x + 2 < 20)
				{
					// 위의 윗칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다.
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.x;
					}

					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '1')
					{
						// 위의 윗칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						// 윗칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] = '1';
						// 플레이어를 이동시킨다.
						++pPlayer->tPos.x;
					}
				}

				else if (pPlayer->bTransparency)
					++pPlayer->tPos.x;
			}

			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;

	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;

	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;

	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;

	case 't':
	case 'T':
		break;
	}
}
// 포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다.
void CreateBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; ++i)
	{
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		// 플레이어가 폭탄에 맞았을 때 시작점으로 보낸다.
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
		{
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}

		for (int j = 1; j <= pPlayer->iBombPower; ++j)
		{
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0')
				{
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';

						else if (iPercent < 80)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
				}

				// 플레이어가 폭탄에 맞았을 때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}

			}

			if (pBombArr[i].y + j < 20)
			{
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0')
				{
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';

						else if (iPercent < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}

				// 플레이어가 폭탄에 맞았을 때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}

			}

			if (pBombArr[i].x - j >= 0)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0')
				{
					Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';

				}

				// 플레이어가 폭탄에 맞았을 때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}

			}

			if (pBombArr[i].x + j < 20)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0')
				{
					// 아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';

						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

				// 플레이어가 폭탄에 맞았을 때 시작점으로 보낸다.
				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
	}

	*pBombCount = 0;
}

int main()
{
	srand((unsigned int)time(0));

	// 20 x 20 미로 생성
	char	strMaze[21][21];

	PLAYER	tPlayer = {};
	POINT	tStarPos;
	POINT	tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;

	POINT tBombPos[5];

	// 미로 설정
	SetMaze(strMaze, &tPlayer, &tStarPos, &tEndPos);

	while (true)
	{
		system("cls");

		// 미로 출력
		Output(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y)
		{
			cout << "SUCCEED!" << endl;
			break;
		}

		cout << "MOVE-WSAD.  SET THE BOMB-T.  DETONATE-U." << endl;
		cout << "INVISIBILITY ON / OFF - I.EXIT - Q.";
		char	cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cInput == 'u' || cInput == 'U')
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cInput == 'i' || cInput == 'I')
		{
			if (tPlayer.bWallPush)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}

		else
			MovePlayer(strMaze, &tPlayer, cInput);
	}

	return 0;
}