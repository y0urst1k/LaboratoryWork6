#pragma once

#include <map>
#include <string>
#include "Lab2/Lab2Module.h"
#include "Lab3/Lab3Module.h"
#include "Lab4/Lab4Module.h"
#include "Lab5/Lab5Module.h"
#include <functional>
#include "Lab6/Lab6Module.h"
#include "Lab7/Lab7Module.h"

using LabFunction = std::function<void()>;

struct LabsManager 
{
private:
    std::map<int, LabFunction> labs;
    std::map<int, std::string> labNames;
    Lab2Module module2;
    Lab3Module module3;
    Lab4Module module4;
    Lab5Module module5;
    Lab6Module module6;
    Lab7Module module7;

    // Добавить
    void AddLab(int number, LabFunction func, const std::string& name);

    // Запуск по номеру
    void RunLab(int number);

    // Показать меню и запустить
    void ShowMenu();

public:
    void Run();

    LabsManager();
};