#include "tetris.h"

GameField::GameField()
{
    field = new wchar_t[FIELD_WIDTH * FIELD_HEIGHT];
    for(int i = 0; i < FIELD_WIDTH * FIELD_HEIGHT; i++)
    {
        field[i] = L' ';
    }
}


wchar_t* GameField::joinToMainField(wchar_t* mainField){
    for(int i = 0; i < FIELD_HEIGHT; i++)
    {
        for(int j = 0; j < FIELD_WIDTH; j++)
        {
            mainField[((i+1) * T_FIELD_WIDTH) + (j+2)] = field[i*FIELD_WIDTH + j];
        }
    }

    return mainField; 
}


void GameField::drawPieceToField(Tetromino t, int x, int y)
{
    
}

void GameField::joinPieceToField(Tetromino t, int x, int y)
{

}

void GameField::removeLine(int lineNum)
{
    for(int i = (lineNum*FIELD_WIDTH) - 1; i > FIELD_WIDTH; i++)
        field[i] = field[i - FIELD_WIDTH];
}

bool GameField::isLineFilled(int lineNum)
{
    for(int i = (lineNum-1)*FIELD_WIDTH; i < (lineNum)*FIELD_WIDTH; i++)
    {
        if (field[i] == L' ') return false;
    }

    return true;
}