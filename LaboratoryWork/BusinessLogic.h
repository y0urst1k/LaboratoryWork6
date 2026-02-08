#pragma once

#include "Data.h"
#include <string>
#include <fstream>
#include <vector>

// Работа с файлами
void ReadDataFromFile(std::vector<Virus>& viruses, std::fstream& file);
void WriteDataInFile(const std::vector<Virus>& viruses, std::fstream& file);

// Вывод информации
void PrintVirus(const Virus& virus);
void PrintAllViruses(const std::vector<Virus>& viruses);

// Очистка
void ClearViruses(vector<Virus>& viruses);

// Сортировка
std::vector<Virus> SortViruses(const std::vector<Virus>& viruses, int property);

// Главное меню
void StartLab1(std::vector<Virus>& viruses);