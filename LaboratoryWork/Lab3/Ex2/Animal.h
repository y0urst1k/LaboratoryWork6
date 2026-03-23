#pragma once

class Animal 
{
public:
    virtual void breathe() = 0;
    virtual void eat() = 0;
    virtual ~Animal() = default;
};