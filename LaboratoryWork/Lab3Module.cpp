#include <iostream>

#include "Lab3Module.h"
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Fish.h"
#include "FlyingBird.h"
#include "HumanManager.h"
#include "Demonstrator.h"

void Lab3Module::StartEx1()
{
    Figure* c = nullptr;

    int number;

    std::cout << "====Menu Figures====" << std::endl
        << "1: Circle" << std::endl
        << "2: Triangle" << std::endl
        << "3: Hexagon" << std::endl
        << "Anything for rectangle" << std::endl
        << "Input number for change figure: ";
    std::cin >> number;

    switch (number) 
    {
    case 1:
        c = new Circle(3);
        break;
    case 2:
        c = new Triangle(3,4);
        break;
    case 3:
        c = new Hexagon(5);
        break;
    default:
        c = new Rectangle(3, 4);
        break;
    }

    if (c != nullptr) 
    {
        std::cout << c->to_string() << std::endl;
        std::cout << calc_cylinder_volume(c, 5) << std::endl;
        delete c;
        c = nullptr;
    }
    else 
    {
        std::cerr << "Ошибка: не удалось создать фигуру" << std::endl;
    }
}

void Lab3Module::StartEx2()
{
    cout << "=== Раннее связывание (прямое создание объектов) ===" << endl;

    //Раннее связывание — прямое создание объектов
    Fish fish;
    Bird bird;
    FlyingBird flyingBird;

    cout << "\n--- Fish ---" << endl;
    fish.breathe();
    fish.eat();
    fish.swim();

    cout << "\n--- Bird ---" << endl;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    cout << "\n--- FlyingBird ---" << endl;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();

    cout << "\n=== Позднее связывание (через указатели на базовый класс) ===" << endl;

    //Позднее связывание — через указатели на базовый класс
    Animal* animalPtr1 = new Fish();
    Animal* animalPtr2 = new Bird();
    Animal* animalPtr3 = new FlyingBird();

    cout << "\n--- Через указатель Animal* на Fish ---" << endl;
    animalPtr1->breathe();
    animalPtr1->eat();

    cout << "\n--- Через указатель Animal* на Bird ---" << endl;
    animalPtr2->breathe();
    animalPtr2->eat();

    cout << "\n--- Через указатель Animal* на FlyingBird ---" << endl;
    animalPtr3->breathe();
    animalPtr3->eat();
    
    delete animalPtr1;
    delete animalPtr2;
    delete animalPtr3;
}

void Lab3Module::StartEx3()
{
    HumanManager manager;
    manager.Start();
}

void Lab3Module::StartEx4()
{
    Demonstrator demonstrator;
    demonstrator.Start();
}

void Lab3Module::StartLab()
{
    std::cout << "Start ex 1" << std::endl;
    StartEx1();
    std::cout << "Finish ex 1";
    std::cout << std::endl;

    std::cout << "Start ex 2" << std::endl;
    StartEx2();
    std::cout << "Finish ex 2";
    std::cout << std::endl;

    std::cout << "Start ex 3" << std::endl;
    StartEx3();
    std::cout << "Finish ex 3";
    std::cout << std::endl;

    std::cout << "Start ex 4" << std::endl;
    StartEx4();
    std::cout << "Finish ex 4";
    std::cout << std::endl;
}