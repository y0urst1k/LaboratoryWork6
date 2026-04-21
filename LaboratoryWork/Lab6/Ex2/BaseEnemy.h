#pragma once

#include "BaseCharacter.h"
#include "Weapon.h"

class BaseEnemy : public BaseCharacter
{
private:
    Weapon* weapon;

public:
    BaseEnemy(double pos_x, double pos_y, Weapon* weapon, int hp)
        : BaseCharacter(pos_x, pos_y, hp), weapon(weapon) {}

    void hit(BaseCharacter& target);

    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy);
};

