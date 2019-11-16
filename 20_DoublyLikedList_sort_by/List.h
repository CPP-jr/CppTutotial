
// #pragma once : 이 헤더파일을 딱 1번만 포함시키겠다 라는 의미이다.
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

// 헤더파일에는 보통 함수 선언 부분을 만들어준다.
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
	// pBegin과 pEnd는 명시적으로 처음과 끝을 의미하도록 만든다. 실제 데이터를 저장하는
	// 노드는 아니다. 실제 데이터를 저장하는 노드는 pBegin과 pEnd 사이에 존재하게 만들어준다.
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;	// 노드 개수
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