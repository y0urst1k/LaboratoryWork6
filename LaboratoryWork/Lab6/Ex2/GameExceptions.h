#pragma once

#include <exception>

class NoWeaponException : public std::exception 
{
public:
    const char* what() const noexcept override 
    {
        return "Я безоружен";
    }
};

class SingleWeaponException : public std::exception 
{
public:
    const char* what() const noexcept override
    {
        return "У меня только одно оружие";
    }
};