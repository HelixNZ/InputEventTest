#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

//Local Includes
#include "eventemitter.hpp"

//Prototypes
class IInputEventListener;
class CInputManager: public CEventEmitter<IInputEventListener>
{
	//Member Functions
private:
	CInputManager();
	~CInputManager();

public:
	static CInputManager& GetInstance();
	static void DestroyInstance();
	static bool IsValid();

	void TestKeyPress(char k);
	void TestKeyRelease(char k);

	void Process();

	//Member Variables
protected:
	static CInputManager* sm_pThis;
};

#endif //__INPUT_MANAGER_H__