#pragma once

#include "Animal.h"
#include <iostream>

using std::cout;
using std::endl;

class Bird : public Animal 
{
public:
    void breathe() override 
    {
        cout << "Bird is breathing air" << endl;
    }

    void eat() override 
    {
        cout << "Bird is eating seeds" << endl;
    }

    void lay_eggs() 
    {
        cout << "Bird is laying eggs" << endl;
    }
};