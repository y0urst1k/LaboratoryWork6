#include "Data.h"
#include "BusinessLogic.h"
#include <iostream>
#include "LabsManager.h"

using std::string;
using std::cout;
using std::cin;

void LabsManager::AddLab(int number, LabFunction func, const string& name) 
{
    labs[number] = func;
    labNames[number] = name;
}

void LabsManager::RunLab(int number) 
{
    auto it = labs.find(number);
    if (it == labs.end()) 
    {
        cout << "LabWork №" << number << " not found!\n";
        return;
    }
    it->second();  // Запускаем функцию лабы
}

void LabsManager::ShowMenu() 
{
    AddLab(1, StartLab1, "Multi-file projects in C++");
    cout << "\n=== LABS MENU ===\n";

    // Выводим список
    for (auto it = labNames.begin(); it != labNames.end(); it++) 
    {
        cout << it->first << ". " << it->second << "\n";  // first = num, second = name
    }
    cout << "0. Exit\n";

    int choice;
    cout << "Choose number (0-exit): ";
    cin >> choice;

    if (choice == 0) {
        cout << "Goodbuy!\n";
        return;
    }

    RunLab(choice);
}