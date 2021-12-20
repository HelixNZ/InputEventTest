#pragma once
#ifndef __INPUT_EVENT_H__
#define __INPUT_EVENT_H__

class CInputManager;
class IInputEvents
{
	//Member Functions
protected:
	IInputEvents();
	virtual ~IInputEvents();
	
private:

	//Empty funcs destined to be overriden
	virtual void OnKeyPressed(char _key) {};
	virtual void OnKeyReleased(char _key) {};

	//Friend for wide support
	friend CInputManager;
};

#endif //__INPUT_EVENT_H__