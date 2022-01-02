//Library Includes
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>

//Local Includes
#include "inputevent.h"
#include "inputmanager.h"

//Test classes
#include "player.hpp"
#include "keylistener.hpp"

//Implementation
int main()
{
	//memleak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	CInputManager& rInput = CInputManager::GetInstance();

	//Scope testing of unsub()
	{
		CPlayer scopedPlayer;

		rInput.TestKeyPress('w');
		rInput.TestKeyPress('d');
		rInput.TestKeyPress('d');
		rInput.TestKeyPress('d');
		rInput.TestKeyPress('w');
		rInput.TestKeyPress('w');
		rInput.TestKeyPress('w');
		rInput.TestKeyPress('s');

		std::cout << "\nBreak\n\n";

		rInput.TestKeyRelease('w');
		rInput.TestKeyPress('a');
	}

	std::cout << "\nTesting outside of player scope\n\n";

	//Test Fire
	rInput.TestKeyPress('w');
	rInput.TestKeyPress('s');
	rInput.TestKeyRelease('a');

	std::cout << "\n\nOpen input testing, press some keys!\n\n";

	//Demo classes for the live test
	CPlayer demoPlayer;
	CKeyListener keys;

	//Listen for escape key
	while(!keys.IsKeyPressed(27))
	{
		rInput.Process();
	}

	rInput.DestroyInstance();

	return(0);
}