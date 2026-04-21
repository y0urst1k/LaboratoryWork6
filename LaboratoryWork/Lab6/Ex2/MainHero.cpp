#include "MainHero.h"
#include "GameExceptions.h"
#include <iostream>

void MainHero::hit(BaseEnemy& target) 
{
    try 
    {
        if (weapons.empty()) 
            throw NoWeaponException();
        weapons[current_weapon_idx]->hit(*this, target);
    }
    catch (const NoWeaponException& e) 
    {
        std::cout << e.what() << "\n";
    }
}

void MainHero::add_weapon(Weapon* weapon) 
{
    weapons.push_back(weapon);
    std::cout << "Подобрал " << *weapon << "\n";

    if (weapons.size() == 1) {
        current_weapon_idx = 0;
    }
}

void MainHero::next_weapon() 
{
    try 
    {
        if (weapons.empty()) 
        {
            throw NoWeaponException();
        }
        else if (weapons.size() == 1) 
        {
            throw SingleWeaponException();
        }
        else 
        {
            current_weapon_idx = (current_weapon_idx + 1) % weapons.size();
            std::cout << "Сменил оружие на " << *weapons[current_weapon_idx] << "\n";
        }
    }
    catch (const NoWeaponException& e) 
    {
        std::cout << e.what() << "\n";
    }
    catch (const SingleWeaponException& e) 
    {
        std::cout << e.what() << "\n";
    }
}

void MainHero::heal(int amount) 
{
    hp += amount;
    if (hp > 200) hp = 200;
    std::cout << "Полечился, теперь здоровья " << hp << "\n";
}

std::ostream& operator<<(std::ostream& os, const MainHero& hero) 
{
    os << "Герой " << hero.name << " на позиции ("
        << hero.pos_x << ", " << hero.pos_y << ")";
    return os;
}