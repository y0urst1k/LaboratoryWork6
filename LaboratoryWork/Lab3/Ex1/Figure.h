#pragma once

#include <string>

class Figure
{
public:
    virtual ~Figure() = default;

    virtual double calc_area() = 0;

    virtual std::string to_string();
};

double calc_cylinder_volume(Figure* base, double height);