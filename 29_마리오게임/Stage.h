#pragma once

#include "value.h"

class CStage
{
public:
	CStage();
	~CStage();

public:
	// �� �Լ��� �׳� �ʱ�ȭ�� ������ �Լ��̴�.
	bool Init();

public:
	char	m_cStage[11][51];

	// �� �Լ��� ���Ͽ��� ������ �о�ͼ� ������ ������ �Լ��̴�.
	bool Init(const char* pFileName);
};

