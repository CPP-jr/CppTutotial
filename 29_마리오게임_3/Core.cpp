#include "Core.h"
#include "MapManager.h"
#include "ObjectManager.h"
#include "Player.h"

CCore* CCore::m_pInst = NULL;

// cpp ���Ͽ��� Ŭ������ �����κ��� �ִ�.
CCore::CCore()
{
	srand((unsigned int)time(0));
}

CCore::~CCore()
{
	CMapManager::DestroyInst();
	CObjectManager::DestroyInst();
}

CCore* CCore::GetInst()
{
	if (!m_pInst)
		m_pInst = new CCore;
	
	return m_pInst;
}

void CCore::DestroyInst()
{
	SAFE_DELETE(m_pInst);
}

bool CCore::Init()
{
	// �� �����ڸ� �ʱ�ȭ�Ѵ�. ���н� false�� �����Ѵ�.
	if (!CMapManager::GetInst()->Init())
		return false;

	// ������Ʈ ������ �ʱ�ȭ
	if (!CObjectManager::GetInst()->Init())
		return false;

	return true;
}

void CCore::Run()
{
	// CMapManager::GetInst()->Render();

	while (true)
	{
		int iStage = OutputMenu();

		if (iStage == 4)
			break;

		else if (iStage == 0)
			continue;

		CMapManager::GetInst()->Run(iStage - 1);
	}
}

int CCore::OutputMenu()
{
	system("cls");
	cout << "1. Stage 1" << endl;
	cout << "2. Stage 2" << endl;
	cout << "3. Stage 3" << endl;
	cout << "4. EXIT" << endl;
	cout << "Input Stage : ";
	int iInput = InputInt();

	if (iInput < 1 || iInput>4)
		return 0;

	return iInput;
}