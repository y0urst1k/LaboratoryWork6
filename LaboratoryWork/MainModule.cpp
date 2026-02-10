#include <iostream>
#include "LabsManager.h"

int main()
{
    setlocale(LC_ALL, "Ru");

    LabsManager manager;
    manager.Run();
    
    //manager.AddLab(1, StartLab1, "Multi-file projects in C++");

    /*
    while (true) 
    {
        manager.ShowMenu();
        int choice;
        std::cin >> choice;

        if (choice == 0) 
        {
            std::cout << "Goodbye!\n";
            break;
        }

        manager.RunLab(choice);
    }
    */
}