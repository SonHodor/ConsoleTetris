#include "tetris.h"

void CApp::OnEvent(SHORT e)
{
    if(e == 27) isRunning = false;

    if(e == 38 || e == 87){}
        // action = 'W';
    if(e == 37 || e == 65){}
        // action = 'A';
    if(e == 40 || e == 83){}
        // action = 'S';
    if(e == 39 || e == 68){}
        // action = 'D';
}