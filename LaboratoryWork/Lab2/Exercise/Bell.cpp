#include "Bell.h"
#include <iostream>

using std::cout;
using std::endl;

void Bell::Sound(int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        if (isDingNext)
        {
            cout << ding << endl;
            isDingNext = false; // Следующий будет dong
        }
        else
        {
            cout << dong << endl;
            isDingNext = true;  // Следующий будет ding
        }
    }
}