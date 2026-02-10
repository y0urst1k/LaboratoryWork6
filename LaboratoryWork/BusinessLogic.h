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
void ClearViruses(std::vector<Virus>& viruses);

// Сортировка
int PartitionByYear(std::vector<Virus>& arr, int low, int high);
void QuickSortByYear(std::vector<Virus>& arr, int low, int high);
int PartitionByName(std::vector<Virus>& arr, int low, int high);
void QuickSortByName(std::vector<Virus>& arr, int low, int high);
std::vector<Virus> SortViruses(const std::vector<Virus>& viruses, int property);

// Главное меню
void StartLab1();