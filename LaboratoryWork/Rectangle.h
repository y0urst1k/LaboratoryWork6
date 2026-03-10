#pragma once

#include <string>
#include "Figure.h"

class Rectangle : public Figure 
{
    double* width;
    double* height;

public:
    Rectangle(double width, double height) 
    {
        this->width = new double(width);
        this->height = new double(height);
    }

    ~Rectangle() override 
    {
        delete this->width;
        delete this->height;
    };

    double calc_area() override 
    {
        return *width * *height;
    };

    std::string to_string() override;
};

