#pragma once

#include <string>

class Human
{
protected:
    std::string name;
    std::string surname;
    std::string patronymic;

public:
    Human();
    Human(const std::string& name, const std::string& surname, const std::string& patronymic);

    std::string getSurnameAndInitials() const;
    std::string getFullName() const;
};