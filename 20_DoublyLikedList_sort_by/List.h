
// #pragma once : �� ��������� �� 1���� ���Խ�Ű�ڴ� ��� �ǹ��̴�.
#pragma once

#include<iostream>

using namespace std;

enum MAIN_NEMU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_SORT,
	MM_EXIT
};

enum OUTPUT_TYPE
{
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE
};

enum SORT_TYPE
{
	ST_NONE,
	ST_NUMBER,
	ST_AVG
};

enum SORT_OPTION
{
	SO_NONE,
	SO_CRIVE,
	SO_DISCRIVE
};

// ������Ͽ��� ���� �Լ� ���� �κ��� ������ش�.
#define NAME_SIZE 32

typedef struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode
{
	STUDENT		tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, * PNODE;

typedef struct _tagList
{
	// pBegin�� pEnd�� ��������� ó���� ���� �ǹ��ϵ��� �����. ���� �����͸� �����ϴ�
	// ���� �ƴϴ�. ���� �����͸� �����ϴ� ���� pBegin�� pEnd ���̿� �����ϰ� ������ش�.
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;	// ��� ����
}LIST, * PLIST;

int InputInt();
void InputString(char* pString, int iSize);
void InitList(PLIST pList);
// void ClearList(PLIST pList);
void DestroyList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
int OutputMenu();
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);
void Sort(PLIST pList);