#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>

#include "inputmanager.h"

template <typename ...S>
void TestFunc(S... _params, void (_func)(bool, bool))
{
	void* test = (void*)_func;
	_func(_params...);
	bool btrue = true;
}

class CPlayer: IInputEvents
{
	//Member Functions
public:
	CPlayer() : x(0), y(0) {};
	~CPlayer() {};

private:
	void OnKeyPressed(char k)
	{
		if(k == 'w') ++y;
		else if(k == 's') --y;
		else if(k == 'd') ++x;
		else if(k == 'a') --x;

		std::cout << "key pressed '" << k << "'; we are now at < " << x << "x , " << y << "y >\n";
	}

	//Member Variables
protected:
	int x;
	int y;
};


int main()
{
	//memleak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	//Interesting concept
	TestFunc<bool, bool>(false, true, [](bool a, bool b)
	{
		std::cout << a << "\n" << b << std::endl;
	});


	CInputManager& rInput = CInputManager::GetInstance();

	//Scope testing of unsub()
	{
		CPlayer newPlayer;

		rInput.TestKeyPress('w');
		rInput.TestKeyPress('d');
		rInput.TestKeyPress('d');
		rInput.TestKeyPress('d');
		rInput.TestKeyPress('w');
		rInput.TestKeyPress('w');
		rInput.TestKeyPress('w');
		rInput.TestKeyPress('s');

		std::cout << "\n\nBreak\n\n";

		rInput.TestKeyRelease('w');
		rInput.TestKeyPress('a');
	}

	std::cout << "\n\nTesting outside of player scope\n\n";

	//Test Fire
	rInput.TestKeyPress('w');
	rInput.TestKeyPress('s');

	std::cout << "\n\ndone";

	rInput.DestroyInstance();

	return(0);
}