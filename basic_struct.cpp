#include<iostream>

using namespace std;

/*
����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
��������� ���� Ÿ���̴�.
���� : struct ����ü�� {}; �� ���·� �����ȴ�.
�迭�� ����ü�� ������
1. ������ �����̴�.
2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.
*/
#define NAME_SIZE 32

struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main()
{
	_tagStudent	tStudent;
	_tagStudent	tStudentArr[100] = {};

	// ����ü ����� �����Ҷ��� . �� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	// tStudent.strName = "aslkdjfwi";
	// ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
	// �� �Լ��� �����ʿ� �ִ� ���ڿ��� �������� �������ش�.
	strcpy_s(tStudent.strName, "�����ٶ� asdf");

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	// �����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�. srtName���� ������
	// �����ٶ� asdf �� ������ �ξ��� ������ �� �ڿ� ������ ���ڿ��� �ٿ���
	// ������ش�.
	strcat_s(tStudent.strName, " ���ڿ� ���̱�");

	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ� �ٸ� ���
	// 0�� �ƴ� ���� ��ȯ�Ѵ�.
	strcpy_s(tStudent.strName, "ȫ�浿");

	cout << "���� �̸��� �Է��ϼ��� : ";
	char	strName[NAME_SIZE] = {};
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "�л��� ���ҽ��ϴ�." << endl;
	}

	else
		cout << "ã�� �л��� �������ϴ�." << endl;
	

	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	// ���ڿ��� ���� �׻� 0(NULL)�� �������Ѵ�. �׷��� �����Ⱚ�� ���ִ�
	// ���¿��� �Ʒ�ó�� �� �迭 ��ҿ� ���� �־��ְ� �Ǹ� �� ���� ��µǰ�
	// �־����� ���� �κ��� �����Ⱚ���� �״�� ��µȴ�. �ֳ��ϸ� ����Ҷ�
	// ���ڿ��� ���� �ν��� �� ���� �����̴�. 0�� ���� �ϴµ� �����Ⱚ��
	// �� �ֱ� �����̴�.
	// tStudent.strName[0] = 'a';
	// tStudent.strName[1] = 'b';
	// tStudent.strName[2] = 0;
		
	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}