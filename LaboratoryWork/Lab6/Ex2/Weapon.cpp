#include "Weapon.h"
#include "BaseCharacter.h"
#include <cmath>
#include <iostream>

void Weapon::hit(const BaseCharacter& actor, BaseCharacter& target) const 
{
    if (!target.is_alive()) 
    {
        std::cout << "Враг уже повержен\n";
        return;
    }

    double distance = std::sqrt(std::pow(target.get_x() - actor.get_x(), 2) + std::pow(target.get_y() - actor.get_y(), 2));

    if (distance > range) 
    {
        std::cout << "Враг слишком далеко для оружия " << name << "\n";
        return;
    }

    std::cout << "Врагу нанесен урон оружием " << name << " в размере " << damage << "\n";
    target.get_damage(damage);
}

std::ostream& operator<<(std::ostream& os, const Weapon& weapon) 
{
    os << weapon.name;
    return os;
}

std::istream& operator>>(std::istream& is, Weapon& weapon) 
{
    std::string name;
    int damage;
    double range;
    is >> name >> damage >> range;
    weapon = Weapon(name, damage, range);
    return is;
}