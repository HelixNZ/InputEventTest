//Library Includes
#include <conio.h>

//Local Includes
#include "inputevent.h"

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
}

CInputManager&
CInputManager::GetInstance()
{
	if(!sm_pThis) sm_pThis = new CInputManager();
	return(*sm_pThis);
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
CInputManager::TestKeyPress(char k)
{
	Emit([&](IInputEventListener& _rListener) { _rListener.OnKeyPressed(k); });
}

void
CInputManager::TestKeyRelease(char k)
{
	Emit([&](IInputEventListener& _rListener) { _rListener.OnKeyReleased(k); });
}

void
CInputManager::Process()
{
	//Console demo, replace with winproc
	if(_kbhit())
	{
		char key = _getch();
		Emit([&](IInputEventListener& _rListener) { _rListener.OnKeyPressed(key); });
	}
}