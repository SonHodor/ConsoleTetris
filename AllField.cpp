#include "tetris.h"


wchar_t* drawCornerSquere(wchar_t* screen, int x1, int y1, int x2, int y2);
wchar_t merge(wchar_t, wchar_t);


wchar_t* AllField::getGameField()
{
    return screen;
}

AllField::AllField()
{
    // - - - - SCREEN INITIALIZATION - - - - - 
	screen = new wchar_t[T_FIELD_WIDTH * T_FIELD_HEIGHT];
    for (int i = 0; i < T_FIELD_WIDTH * T_FIELD_HEIGHT; i++) 
    	screen[i] = L' ';

	screen = gField.joinToMainField(screen);

	// main corner
	screen = drawCornerSquere(screen, 0, 0, T_FIELD_WIDTH, T_FIELD_HEIGHT);
	//around game field
	screen = drawCornerSquere(screen, 0, 0, FIELD_WIDTH+4, T_FIELD_HEIGHT);
	// around "your score"
	screen = drawCornerSquere(screen, FIELD_WIDTH+3, 8, T_FIELD_WIDTH, 11);
	// around next tetro
	screen = drawCornerSquere(screen, FIELD_WIDTH+5, 1, FIELD_WIDTH+5 + 14, 8);
    // - - - - SCREEN - - - - - 


	currTetro = clock() % 7;
	nextTetro = (clock() + 0) % 7;

	drawNextTetroWindow(nextTetro);
}

void AllField::drawNextTetroWindow(int tetroNum)
{
	Tetromino teto = Tetromino(tetroNum);

	wchar_t color = L'█';

	wchar_t nextField[8 * 4];

	const int FROM_LEFT = 27;
	const int FROM_UP = 2;

    for(int i = 0; i < 16; i++)
	{
		// drawing piece to array
		if(teto.getTetro()[i] == L'0')
		{
			nextField[i*2] = L' ';
			nextField[i*2 + 1] = L' ';
		}
		else
		{
			nextField[i*2] = color;
			nextField[i*2 + 1] = color;
		}
	}

	int i = 0;
	for(int y = 0; y < 4; y++)
	{
		for(int x = 0; x < 8; x++)
		{
			i = T_FIELD_WIDTH * (y+FROM_UP) + (x+FROM_LEFT);
			screen[i] = nextField[8*y + x];
		}
	}
}


wchar_t* drawCornerSquere(wchar_t* screen, int x1, int y1, int x2, int y2)
{
	// 		 --------> X
	// 		|
	// 		|
	// 		|
	// 	  Y V

	wchar_t I[2] = {L'║', L'═'};
	wchar_t L[4] = {L'╔', L'╚', L'╗', L'╝'};

	// creating new area, to fill it with corner
	int areaSizeX = x2-x1;
	int areaSizeY = y2-y1;
	wchar_t cornerArea[areaSizeX * areaSizeY];

	for(int y = 0; y < areaSizeY; y++)
	{
		for(int x = 0; x < areaSizeX; x++)
		{
			cornerArea[y*areaSizeX + x] = L' ';

			// Strait lines
			if((x == 0) || (x == (areaSizeX - 1)))
				cornerArea[y*areaSizeX + x] = I[0];
			if((y == 0) || (y == (areaSizeY - 1)))
				cornerArea[y*areaSizeX + x] = I[1];

			// corners
			if((x == 0) && (y == 0))
				cornerArea[y*areaSizeX + x] = L[0];
			if((x == 0) && (y == (areaSizeY - 1)))
				cornerArea[y*areaSizeX + x] = L[1];
			if((x == (areaSizeX - 1)) && (y == 0))
				cornerArea[y*areaSizeX + x] = L[2];
			if((x == (areaSizeX - 1)) && (y == (areaSizeY - 1)))
				cornerArea[y*areaSizeX + x] = L[3];
		}
	}

	for(int y = 0; y < areaSizeY; y++)
	{
		for(int x = 0; x < areaSizeX; x++)
		{
			wchar_t ch_1 = screen[T_FIELD_WIDTH * (y + y1) + (x + x1)];
			wchar_t ch_2 = cornerArea[areaSizeX * y + x];
			screen[T_FIELD_WIDTH * (y + y1) + (x + x1)] = merge(ch_1, ch_2);
		}
	}

	return screen;
}

wchar_t merge(wchar_t scrCh, wchar_t corCh)
{
	bool isLine(wchar_t);

	if(!isLine(corCh)) return scrCh;
	if(!isLine(scrCh)) return corCh;

	// ultimate shitfuck
	switch(scrCh)
	{
	case L'╬':
		return scrCh;
	case L'╣':
		switch(corCh)
		{
		case L'║':
		case L'╗':
		case L'╝':
			return L'╣';
		case L'═':
		case L'╔':
		case L'╚':
			return L'╬';
		}
	case L'╠':
		switch(corCh)
		{
		case L'║':
		case L'╔':
		case L'╚':
			return L'╠';
		case L'╗':
		case L'═':
		case L'╝':
			return L'╬';
		}
	case L'╩':
		switch(corCh)
		{
		case L'═':
		case L'╚':
		case L'╝':
			return L'╩';
		case L'║':
		case L'╔':
		case L'╗':
			return L'╬';
		}
	case L'╦':
		switch(corCh)
		{
		case L'═':
		case L'╔': 
		case L'╗':
			return L'╦';
		case L'║':
		case L'╝':
		case L'╚':
			return L'╬';
		}
	case L'╚':
		switch(corCh)
		{
		case L'║':
		case L'╔':
			return L'╠';
		case L'═':
		case L'╝':
			return L'╩';
		case L'╚':
			return L'╚';
		case L'╗':
			return L'╬';
		}
	case L'╝':
		switch(corCh)
		{
		case L'║':
		case L'╗':
			return L'╣';
		case L'═':
		case L'╚':
			return L'╠';
		case L'╝':
			return L'╝';
		case L'╔':
			return L'╬';
		}
	case L'╗':
		switch(corCh)
		{
		case L'║':
		case L'╝':
			return L'╣';
		case L'═':
		case L'╔':
			return L'╦';
		case L'╗':
			return L'╗';
		case L'╚':
			return L'╬';
		}
	case L'╔':
		switch(corCh)
		{
		case L'║':
		case L'╚':
			return L'╠';
		case L'═':
		case L'╗':
			return L'╦';
		case L'╔':
			return L'╔';
		case L'╝':
			return L'╬';
		}
	case L'═':
		switch(corCh)
		{
		case L'═':
			return L'═';
		case L'╔':
		case L'╗':
			return L'╦';
		case L'╝':
		case L'╚':
			return L'╩';
		case L'║':
			return L'╬';
		}
	case L'║':
		switch(corCh)
		{
		case L'║':
			return L'║';
		case L'╔':
		case L'╚':
			return L'╠';
		case L'╗':
		case L'╝':
			return L'╣';
		case L'═':
			return L'╬';
		}
	}
}

bool isLine(wchar_t ch)
{
	wchar_t all[11] = {L'║', L'═', L'╔', L'╗', L'╝', L'╚', L'╦', L'╩', L'╠', L'╣', L'╬'};
	for (int iter = 0; iter < 11; iter++)
	{
		if (ch == all[iter]) return true;
	}
	return false;
}