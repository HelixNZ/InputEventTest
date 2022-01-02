#pragma once
#ifndef __KEY_LISTENER_H__
#define __KEY_LISTENER_H__

//Local Includes
#include "inputevent.h"

//Prototype
class CKeyListener: IInputEventListener
{
	//Member Functions
public:
	CKeyListener() { for(auto i = 0; i < 128; ++i) keys[i] = false; }
	~CKeyListener() {};

	bool IsKeyPressed(char k) { return(keys[k]); }

private:
	void OnKeyPressed(char k) { keys[k] = true; }
	void OnKeyReleased(char k) { keys[k] = false; }

	//Member Variables
private:
	bool keys[128];
};

#endif //__KEY_LISTENER_H__