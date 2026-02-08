#include "Data.h"
#include "BusinessLogic.h"
#include <iostream>
#include "LabsManager.h"

void LabsManager::AddLab(int number, LabFunction func, const std::string& name) {
    labs[number] = func;
    labNames[number] = name;
}

void LabsManager::RunLab(int number) 
{
    auto it = labs.find(number);
    if (it == labs.end()) 
    {
        std::cout << "LabWork №" << number << " not found!\n";
        return;
    }
    it->second();  // Запускаем функцию лабы
}

void LabsManager::ShowMenu() {
    std::cout << "\n=== LABS MENU ===\n";

    // Выводим список
    for (const auto& [num, name] : labNames) {
        std::cout << num << ". " << name << "\n";
    }
    std::cout << "0. Выход\n";

    int choice;
    std::cout << "Выберите номер (0-выход): ";
    std::cin >> choice;

    if (choice == 0) {
        std::cout << "До свидания!\n";
        return;
    }

    RunLab(choice);
}