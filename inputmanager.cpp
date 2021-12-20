//This Include
#include "inputmanager.h"

//Static decl.
CInputManager* CInputManager::sm_pThis = nullptr;

//Implementation
CInputManager::CInputManager()
{
	//Constructor
}

CInputManager::~CInputManager()
{
	//Destructor
	m_pWatchers.clear(); //We have zero ownership over these
}

CInputManager&
CInputManager::GetInstance()
{
	if(!sm_pThis) sm_pThis = new CInputManager();
	return *sm_pThis;
}

void
CInputManager::DestroyInstance()
{
	if(sm_pThis) delete sm_pThis;
	sm_pThis = nullptr;
}

bool
CInputManager::IsValid()
{
	return(sm_pThis != nullptr);
}

void
CInputManager::Subscribe(IInputEvents* _pWho)
{
	m_pWatchers.push_back(_pWho);
}

void
CInputManager::Unsubscribe(IInputEvents* _pWho)
{
	for(auto i = 0; i < m_pWatchers.size(); ++i)
	{
		if(m_pWatchers[i] != _pWho) continue;
		m_pWatchers.erase(m_pWatchers.begin() + i);
		break;
	}
}

void
CInputManager::TestKeyPress(char k)
{
	for(auto i = 0; i < m_pWatchers.size(); ++i)
	{
		m_pWatchers[i]->OnKeyPressed(k);
	}
}

void
CInputManager::TestKeyRelease(char k)
{
	for(auto i = 0; i < m_pWatchers.size(); ++i)
	{
		m_pWatchers[i]->OnKeyReleased(k);
	}
}