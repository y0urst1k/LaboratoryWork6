#include "BaseEnemy.h"
#include <ostream>

void BaseEnemy::hit(BaseCharacter& target)
{
    weapon->hit(*this, target);
}

std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy) 
{
    os << "Враг на позиции (" << enemy.pos_x << ", " << enemy.pos_y
        << ") с оружием " << *enemy.weapon;
    return os;
}