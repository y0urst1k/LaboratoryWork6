#include "Human.h"

Human::Human() : name("Неизвестно"), surname("Неизвестно"), patronymic("Неизвестно") {}

Human::Human(const std::string& name, const std::string& surname, const std::string& patronymic)
    : name(name), surname(surname), patronymic(patronymic) {}

std::string Human::getSurnameAndInitials() const 
{
    return surname + " " + name[0] + "." + patronymic[0] + ".";
}

std::string Human::getFullName() const 
{
    return surname + " " + name + " " + patronymic;
}