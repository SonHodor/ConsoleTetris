#pragma once
#ifndef _GAME_F_H_
	#define _GAME_F_H_

class GameField
{
public:
    GameField();

    wchar_t* joinToMainField(wchar_t*);
    void fieldDown();

    // when piece is falling
    void drawPieceToField(Tetromino t, int x, int y);
    // when piece fell
    void joinPieceToField(Tetromino t, int x, int y);
    bool isTerominoFits(Tetromino t, int x, int y);
    
private:

    wchar_t* field;
};

#endif