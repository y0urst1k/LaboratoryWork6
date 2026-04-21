#pragma once

#include <string>

class Weapon
{
private:
    std::string name;
    int damage;
    double range;

public:
    Weapon(const std::string& name, int damage, double range)
        : name(name), damage(damage), range(range) {}

    void hit(const class BaseCharacter& actor, class BaseCharacter& target) const;

    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);
    friend std::istream& operator>>(std::istream& is, Weapon& weapon);

    std::string get_name() const { return name; }
    int get_damage() const { return damage; }
    double get_range() const { return range; }
};

