#pragma once

#include "BaseCharacter.h"
#include <vector>
#include <string>
#include "Weapon.h"
#include "BaseEnemy.h"

class MainHero : public BaseCharacter
{
private:
    std::string name;
    std::vector<Weapon*> weapons;
    size_t current_weapon_idx;

public:
    MainHero(double pos_x, double pos_y, const std::string& name, int hp)
        : BaseCharacter(pos_x, pos_y, hp), name(name), current_weapon_idx(0) {}

    void hit(BaseEnemy& target);
    void add_weapon(Weapon* weapon);
    void next_weapon();
    void heal(int amount);

    friend std::ostream& operator<<(std::ostream& os, const MainHero& hero);
};

