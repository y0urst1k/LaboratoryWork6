#include "BaseCharacter.h"

void BaseCharacter::move(double delta_x, double delta_y) 
{
    pos_x += delta_x;
    pos_y += delta_y;
}

bool BaseCharacter::is_alive() const 
{
    return hp > 0;
}

void BaseCharacter::get_damage(int amount) 
{

    hp -= amount;
    if (hp < 0) hp = 0;
}