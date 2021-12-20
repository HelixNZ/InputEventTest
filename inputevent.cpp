//Local Includes
#include "inputmanager.h"

//This Include
#include "inputevent.h"

//Implementation
IInputEvents::IInputEvents()
{
	if(!CInputManager::IsValid()) throw false;
	CInputManager::GetInstance().Subscribe(this);
};

IInputEvents::~IInputEvents()
{
	if(CInputManager::IsValid()) CInputManager::GetInstance().Unsubscribe(this);
};