#include "tetris.h"

Tetromino::Tetromino(int next_p)
{
    rotation = 0;
    piece = next_p;
}


void Tetromino::rotate(int r)
{
    if(r < 0)
        rotation = ((rotation + 3) - r) % 4;
    else
        rotation = (rotation + 1) % 4;
}


wchar_t* Tetromino::getTetro()
{
    return pieces[piece][rotation];
}