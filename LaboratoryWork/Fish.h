#pragma once

#include "Animal.h"
#include <iostream>

using std::cout;
using std::endl;

class Fish : public Animal 
{
public:
    void breathe() override 
    {
        cout << "Fish is breathing underwater" << endl;
    }

    void eat() override 
    {
        cout << "Fish is eating plankton" << endl;
    }

    void swim()
    {
        cout << "Fish is swimming" << endl;
    }
};