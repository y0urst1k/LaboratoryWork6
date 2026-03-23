#include "Demonstrator.h"
#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

int Demonstrator::sumNaturalNumbers(int N)
{
    return N * (N + 1) / 2;
}

int Demonstrator::sumSquares(int N)
{
    return N * (N + 1) * (2 * N + 1) / 6;
}

int Demonstrator::sumCubes(int N)
{
    return (N * (N + 1) / 2) * (N * (N + 1) / 2);
}

void Demonstrator::demonstrateEarlyBinding()
{
    std::cout << "=== Раннее связывание ===" << std::endl;

    Summator s;
    SquareSummator sq;
    CubeSummator c;

    const int N = 5;

    std::cout << "N = " << N << std::endl;
    std::cout << "Сумма натуральных чисел: " << s.sum(N)
        << " (ожидаемо: " << sumNaturalNumbers(N) << ")" << std::endl;
    std::cout << "Сумма квадратов: " << sq.sum(N)
        << " (ожидаемо: " << sumSquares(N) << ")" << std::endl;
    std::cout << "Сумма кубов: " << c.sum(N)
        << " (ожидаемо: " << sumCubes(N) << ")" << std::endl;
}

void Demonstrator::demonstrateLateBinding()
{
    std::cout << "\n=== Позднее связывание ===" << std::endl;

    const int N = 5;
    Summator* ptr;

    ptr = new Summator();
    std::cout << "Сумма натуральных чисел: " << ptr->sum(N)
        << " (ожидаемо: " << sumNaturalNumbers(N) << ")" << std::endl;
    delete ptr;

    ptr = new SquareSummator();
    std::cout << "Сумма квадратов: " << ptr->sum(N)
        << " (ожидаемо: " << sumSquares(N) << ")" << std::endl;
    delete ptr;

    ptr = new CubeSummator();
    std::cout << "Сумма кубов: " << ptr->sum(N)
        << " (ожидаемо: " << sumCubes(N) << ")" << std::endl;
    delete ptr;
}

void Demonstrator::Start()
{
    demonstrateEarlyBinding();
    demonstrateLateBinding();
}