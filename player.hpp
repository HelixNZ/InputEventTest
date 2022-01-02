#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

//Library Includes
#include <iostream>

//Local Includes
#include "inputevent.h"

//Player test class
class CPlayer: IInputEventListener
{
	//Member Functions
public:
	CPlayer(): x(0), y(0) {};
	~CPlayer() {};

private:
	void OnKeyPressed(char k)
	{
		if(k == 'w') ++y;
		else if(k == 's') --y;
		else if(k == 'd') ++x;
		else if(k == 'a') --x;

		//Ignore cout if not correct key
		if(k == 'w' || k == 'a' || k == 's' || k == 'd')
		{
			std::cout << "key pressed '" << k << "'; we are now at < " << x << "x , " << y << "y >\n";
		}
	}

	void OnKeyReleased(char k)
	{
		//Ignore cout if not correct key
		if(k == 'w' || k == 'a' || k == 's' || k == 'd')
		{
			std::cout << "key released '" << k << "'\n";
		}
	}

	//Member Variables
protected:
	int x;
	int y;
};

#endif //__PLAYER_H__