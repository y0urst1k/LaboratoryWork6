#pragma once

#include "Bird.h"
#include <iostream>

using std::cout;
using std::endl;

class FlyingBird : public Bird 
{
public:
    void fly() 
    {
        cout << "FlyingBird is flying" << endl;
    }
};