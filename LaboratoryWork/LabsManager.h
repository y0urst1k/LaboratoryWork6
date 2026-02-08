#pragma once

#include <map>
#include <string>

// Функция лабораторной работы
using LabFunction = void(*)(void);

struct LabsManager 
{
private:
    std::map<int, LabFunction> labs;
    std::map<int, std::string> labNames;

public:
    // Добавить лабу
    void AddLab(int number, LabFunction func, const std::string& name);

    // Запустить лабу по номеру
    void RunLab(int number);

    // Показать меню и запустить
    void ShowMenu();
};