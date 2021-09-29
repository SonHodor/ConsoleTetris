#include "tetris.h"

CApp::CApp()
{
	isRunning = true;
	dwBytesWritten = 0;

	fps.prevTime = clock();
    fps.timeToSleep = 0;
    fps.iterationTime = 0;
}

int CApp::onExecute()
{
	if(OnInit() == false)
		return -1;

	while (isRunning) 
	{
		for(int q=8;q<=256;q++)
			if(GetAsyncKeyState(q)==-32767)
                OnEvent(q);
		OnLoop();
		OnRender();
	}

	OnCleanup();
	return 0;
}

void CApp::fpsSleep()
{
	fps.iterationTime = clock() - fps.prevTime;
    fps.timeToSleep = fps.MS_IN_FRAME - fps.iterationTime;
    if (fps.timeToSleep < 0) fps.timeToSleep = 0; 
    
    Sleep(fps.timeToSleep);
     
    // cout << "i just slept for " << timeToSleep << "ms + " << iterationTime << endl;
    fps.prevTime = clock();
}

int main(int argc, char* argv[])
{
	CApp theApp;

	return theApp.onExecute();
}
// g++ CApp_OnInit.cpp CApp.cpp CApp_OnRender.cpp CApp_OnEvent.cpp CApp_OnLoop.cpp CApp_OnCleanup.cpp AllField.cpp GameField.cpp Tetromino.cpp -o main.exe