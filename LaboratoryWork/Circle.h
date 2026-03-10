#pragma once

#define _USE_MATH_DEFINES

#include <string>
#include <math.h>

#include "Figure.h"

class Circle : public Figure 
{
    double* radius;

public:
    Circle(double radius) 
    {
        this->radius = new double(radius);
    }

    ~Circle() override 
    {
        delete this->radius;
    }

    double calc_area() override 
    {
        const double r = *this->radius;

        return r * r * M_PI;
    }

    std::string to_string() override;
};

