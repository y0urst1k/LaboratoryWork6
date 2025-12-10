#pragma once

#include "Data.h"
#include "MyList.h"
#include <string>
#include <fstream>

// --- Объявления функций для работы с датами ---
time_t ParseDate(const std::string& dateStr);

// --- Конвертация строк в перечисления ---
CarMark CarMarkFromString(const std::string&);
CarColor CarColorFromString(const std::string& str);
CarBodywork CarBodyworkFromString(const std::string& str);

// --- Вспомогательные функции для пользовательского ввода (меню выбора) ---
void PrintCarMarksWithNumbers();
CarMark GetCarMarkByNumber(int num);


void PrintCarColorsWithNumbers();
CarColor GetCarColorByNumber(int num);

void PrintCarBodyworksWithNumbers();
CarBodywork GetCarBodyworkByNumber(int num);

// --- Работа с файлами ---
void ReadDataFromFile(MyList& cars, std::fstream& file);
void WriteDataInFile(const MyList& cars, std::fstream& file);

// --- Вывод информации ---
void PrintCar(const Car& car);
void PrintAllCars(const MyList& cars);

// --- Поиск ---
void FindByMark(const MyList& cars, CarMark mark);
void FindByOwner(const MyList& cars, const std::string& name,
    const std::string& surname, const std::string& patronymic);

// --- Управление списком ---
Car InputCar();
void DeleteCarByIndex(MyList& cars);
void ClearCars(MyList& cars);

// --- Главное меню ---
void Menu(MyList& cars);