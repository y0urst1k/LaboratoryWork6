#include "Lab3Module.h"
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Hexagon.h"

#include <iostream>

void Lab3Module::StartEx1()
{
    Figure* c = nullptr;

    int number;
    std::cin >> number;

    switch (number) 
    {
    case 1:
        c = new Circle(3);
        break;
    case 2:
        c = new Triangle(3,4);
    case 3:
        c = new Hexagon(5);
    default:
        c = new Rectangle(3, 4);
        break;
    }

    std::cout << c->to_string() << std::endl;
    std::cout << calc_cylinder_volume(c, 5) << std::endl;
}