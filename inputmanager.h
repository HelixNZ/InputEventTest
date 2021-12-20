#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

//Library Includes
#include <vector>

//Local Includes
#include "inputevent.h"

//Prototypes
class IInputEvents;
class CInputManager
{
public:
	static CInputManager& GetInstance();
	static void DestroyInstance();

	static bool IsValid();


	void Subscribe(IInputEvents* _pWho);
	void Unsubscribe(IInputEvents* _pWho);

	void TestKeyPress(char k);
	void TestKeyRelease(char k);

private:
	CInputManager();
	~CInputManager();

	static CInputManager* sm_pThis;
	std::vector<IInputEvents*> m_pWatchers;
};



#endif //__INPUT_MANAGER_H__