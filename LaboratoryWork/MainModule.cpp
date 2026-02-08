#include <iostream>
#include "LabsManager.h"

int main()
{
    setlocale(LC_ALL, "Ru");

    LabsManager manager;

    // Запускаем меню
    while (true) 
    {
        manager.ShowMenu();
        int choice;
        std::cin >> choice;
        if (choice == 0) 
            break;
    }

}