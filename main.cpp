#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

const int T_FIELD_WIDTH = 80;
const int T_FIELD_HEIGHT = 24;

int main()
{
    for(char i = 1; i < 255; i++)
        cout << int(i) << " = " << i << endl;
}