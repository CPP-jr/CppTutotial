#pragma once

#include "value.h"

class CStage
{
public:
	CStage();
	~CStage();

public:
	// 이 함수는 그냥 초기화할 목적의 함수이다.
	bool Init();

public:
	char	m_cStage[11][51];

	// 이 함수는 파일에서 정보를 읽어와서 설정할 목적의 함수이다.
	bool Init(const char* pFileName);
};

