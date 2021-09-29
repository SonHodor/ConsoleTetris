#include "tetris.h"

bool CApp::OnInit()
{
	if (!true) // place holder
		return false;
	else
	{
		hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);

		return true;
	}
}