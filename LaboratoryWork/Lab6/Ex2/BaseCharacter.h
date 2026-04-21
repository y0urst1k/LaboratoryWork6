#pragma once
class BaseCharacter
{
protected:
    double pos_x, pos_y;
    int hp;

public:
    BaseCharacter(double pos_x, double pos_y, int hp)
        : pos_x(pos_x), pos_y(pos_y), hp(hp) {}

    virtual void move(double delta_x, double delta_y);
    bool is_alive() const;
    void get_damage(int amount);
    double get_x() const { return pos_x; }
    double get_y() const { return pos_y; }
    int get_hp() const { return hp; }

    virtual ~BaseCharacter() = default;
};

