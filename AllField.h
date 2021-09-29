#pragma once
#ifndef _ALL_F_H_
	#define _ALL_F_H_

class AllField
{
public:

    GameField       gField;

    AllField();

    int currTetro;
    int nextTetro;

    wchar_t* getGameField();

private:
	wchar_t*		screen;

    // draws tetro to window "NEXT"
    void drawNextTetroWindow(int);

};

#endif