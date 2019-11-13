#include<iostream>
#include<time.h>

// console input output ��������̴�. �ܼ�â���� ����� �ϴ� ��ɵ���
// �������ִ� ��������̴�.
#include<conio.h>

/*
���� : ���ں�������� ������.
1 ~ 25 ������ ���ڰ� �ְ� �� ���ڸ� ����� ��� 5 x 5 �� ����Ѵ�.
�÷������� ���ڸ� �Է¹޴´�. 1 ~ 25 ������ ���ڸ� �Է¹޾ƾ� �Ѵ�.
0�� �Է��ϸ� ������ �����Ѵ�.

���ڸ� �Է��޾����� ���ڸ���� �Է¹��� ���ڸ� ã�Ƽ� *�� �����д�.
���ڸ� *�� ���� �Ŀ� ���� �� ���� üũ�Ѵ�. 5 x 5 �̱� ������ ���� 5�� ���� 5��
�밢�� 2���� ���� �� �ִ�. �������� ���������� üũ�ؼ� ȭ�鿡 �����ش�.
5�� �̻��� ��� ������ �����Ѵ�.
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

	// ���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ����
	// ����Ұǵ� INT_MAX��� ���� ����Ұ��̴�. INT_MAX�� �̹� ���ǵǾ��ִ� ������
	// int�� ǥ���� �� �ִ� �ִ밪�̴�.
	iNumber[24] = INT_MAX;

	// ���� �ִ� ��ġ�� ������ ������ ������ش�.
	int iStarIndex = 24;

	// ������ ���谳�� �����ϰ� 1 ~ 24 ������ ���ڸ� �����ش�. ��, �ε����� 0 ~ 23��
	// �ε��� ������ �����ش�.
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
		// i for���� �������� �ǹ��Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			// j for���� ���� ĭ�� �ǹ��Ѵ�.
			for (int j = 0; j < 5; ++j)
			{
				// i�� 0�� �� j�� 0 ~ 4���� �ݺ��Ѵ�. �� ��� 0 * 5 + (0 ~ 4)�� ���ϰԵż�
				// �ε����� 0, 1, 2, 3, 4 �� ������ �ȴ�.
				// i�� 1�� �� j�� 0 ~ 4 ���� �ݺ��Ѵ�. �̰�� 1 * 5 + (0 ~ 4)�� ���ϰԵż�
				// �ε����� 5, 6, 7, 8, 9 �� ������ �ȴ�.
				// i�� 2�� �� j�� 0 ~ 4 ���� �ݺ��Ѵ�. �̰�� 2 * 5 + (0 ~ 4)�� ���ϰԵż�
				// �ε����� 10, 11, 12, 13, 14 �� ������ �ȴ�.
				// i�� 3�� �� j�� 0 ~ 4 ���� �ݺ��Ѵ�. �̰�� 3 * 5 + (0 ~ 4)�� ���ϰԵż�
				// �ε����� 15, 16, 17, 18, 19 �� ������ �ȴ�.
				// i�� 4�� �� j�� 0 ~ 4 ���� �ݺ��Ѵ�. �̰�� 4 * 5 + (0 ~ 4)�� ���ϰԵż�
				// �ε����� 20, 21, 22, 23, 24 �� ������ �ȴ�.
				// �ٹ�ȣ * ���ΰ��� + ĭ��ȣ

				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		// true�� �־ ���� ��� ����� ��� �����صд�.
		bool	bWin = true;

		// ������ ���߾����� üũ�Ѵ�.
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
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		cout << "WSAD : �̵�. Q : ����.";
		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ��̴�. �� �Լ��� Enter�� ġ�� �ʴ����
		// ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� �����Ѵ�.
		char	cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			// ���� ������ ���� w�� ������ ���� �ö󰡼��� �� �ȴ�.
			if (iStarIndex > 4)
			{
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// ���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 5] = INT_MAX;
				// ���� ��ĭ ���� �ö����Ƿ� ��ĭ���� �ε����� ������ش�.
				iStarIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			// ���� �Ʒ����� �ƴ� ��� �����δ�.
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

	cout << endl << "������ �����մϴ�." << endl;

	return 0;
}