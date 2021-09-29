#pragma once
#ifndef _CAPP_H_
	#define _CAPP_H_

#ifndef UNICODE
#define UNICODE
#define UNICODE_WAS_UNDEFINED
#endif

#include <winuser.h>
#include <Windows.h>

#include "tetris.h"

#ifdef UNICODE_WAS_UNDEFINED
#undef UNICODE
#endif


using namespace std;

class CApp
{
private:
	bool			isRunning;

	HANDLE 			hConsole;

	DWORD 			dwBytesWritten;

	AllField		allField;

	struct eqFps{
		int prevTime;
    	const float FPS_NEEDED = 15.0;
    	const int MS_IN_FRAME = (1.0 / FPS_NEEDED) * 1000;
    	int timeToSleep;
    	int iterationTime;
	} fps;

	void			fpsSleep();

public:
	CApp();

	int onExecute();

public:
	bool OnInit();
	void OnEvent(SHORT e);
	void OnLoop();
	void OnRender();
	void OnCleanup();
};

#endif