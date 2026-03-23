#include "StockManager.h"
#include <iostream>

void StockManager::PrintMenu() 
{
    std::cout << "\n=== Stock managing ===\n";
    std::cout << "1. Add box\n";
    std::cout << "2. Get box by weight\n";
    std::cout << "3. Get box by volume\n";
    std::cout << "0. Exit\n";
    std::cout << "Change action: ";
}

void StockManager::ClearInputBuffer() 
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void StockManager::AddBox(Stock& stock) 
{
    int weight, volume;

    std::cout << "Input weight of box: ";
    while (!(std::cin >> weight)) 
    {
        std::cout << "Error! Input number: ";
        ClearInputBuffer();
    }

    std::cout << "Input volume of box: ";
    while (!(std::cin >> volume)) 
    {
        std::cout << "Error! Input number: ";
        ClearInputBuffer();
    }

    stock.Add(weight, volume);
    std::cout << "Add box with ID: " << stock.GetNextId() << "\n"; // ID последней добавленной коробки
}

void StockManager::GetByWeight(Stock& stock) {
    int minWeight;
    std::cout << "Input min weight: ";
    while (!(std::cin >> minWeight)) 
    {
        std::cout << "Error! Input number: ";
        ClearInputBuffer();
    }

    int id = stock.GetByW(minWeight);
    if (id != -1) 
    {
        std::cout << "Get box with ID: " << id << "\n";
    }
    else 
    {
        std::cout << "No matching boxes were found!\n";
    }
}

void StockManager::GetByVolume(Stock& stock) {
    int minVolume;
    std::cout << "Input min volume: ";
    while (!(std::cin >> minVolume)) 
    {
        std::cout << "Error! Input number: ";
        ClearInputBuffer();
    }

    int id = stock.GetByV(minVolume);
    if (id != -1) 
    {
        std::cout << "Get box with ID: " << id << "\n";
    }
    else 
    {
        std::cout << "No matching boxes were found\n";
    }
}

void StockManager::Run()
{
    Stock warehouse;
    int choice;

    do {
        PrintMenu();
        if (!(std::cin >> choice)) 
        {
            std::cout << "Input error! Please, input number.\n";
            ClearInputBuffer();
            continue;
        }

        switch (choice) 
        {
        case 1:
            AddBox(warehouse);
            break;
        case 2:
            GetByWeight(warehouse);
            break;
        case 3:
            GetByVolume(warehouse);
            break;
        case 0:
            std::cout << "Goodbue!\n";
            break;
        default:
            std::cout << "Incorrect choice! Try again.\n";
        }
    } while (choice != 0);
}