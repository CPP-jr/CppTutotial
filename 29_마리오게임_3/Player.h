#pragma once

#include "value.h"

enum JUMP_DIR
{
	JD_STOP,
	JD_UP,
	JD_DOWN
};

#define JUMP_BLOCK_MAX 2

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	POINT	m_tPos;
	bool	m_bJump;
	int		m_iJumpDir;
	int		m_iJumpState;
	int		m_iScore;
	bool	m_bComplete;
	bool	m_bBulletFire;
	bool	m_bBigItem;

public:
	int GetX()
	{
		return m_tPos.x;
	}

	int GetY()
	{
		return m_tPos.y;
	}

	int GetScore()
	{
		return m_iScore;
	}

	bool GetComplete()
	{
		return m_bComplete;
	}

	bool GetBigItemEnalbe()
	{
		return m_bBigItem;
	}

public:
	void Reset()
	{
		m_bComplete = false;
		m_bBulletFire = false;
		m_bBigItem = false;
		m_iScore = 0;
	}

public:
	void SetPos(int x, int y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

public:
	bool	Init();
	void	Update();
};

