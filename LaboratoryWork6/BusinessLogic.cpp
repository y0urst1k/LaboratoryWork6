#include "Data.h"
#include "ConvertDataToStr.h"
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;
using std::string;

void PrintCar(const Car& car) 
{
    cout << "Марка: " << CarMarkToString(car.carmark) << endl;
    cout << "Страна-производитель: " << CountryToString(modelToCountry.at(car.carmark)) << endl;
    cout << "Цвет: " << CarColorToString(car.carColor) << endl;
    cout << "Заводской номер: " << car.factorynumber << endl;
    cout << "Дата выпуска: " << asctime(localtime(&car.releaseDate));
    cout << "Дата ТО: " << asctime(localtime(&car.technicalInspectionDate));
    cout << "Кузов: " << CarBodyworkToString(car.carBodywork) << endl;
    cout << "Владелец: " << car.name << " " << car.surname << " " << car.patronymic << endl;
    cout << "----------------------------------------" << endl;
}

// Функция вывода всех автомобилей
void PrintAllCars(const vector<Car>& cars) 
{
    if (cars.empty()) 
    {
        cout << "Список автомобилей пуст." << endl;
        return;
    }
    for (size_t i = 0; i < cars.size(); i++) 
    {
        cout << "Автомобиль #" << (i + 1) << ":" << endl;
        PrintCar(cars[i]);
    }
}

// Поиск по марке
void FindByMark(const vector<Car>& cars, CarMark mark) 
{
    bool found = false;
    for (const auto& car : cars) 
    {
        if (car.carmark == mark) 
        {
            PrintCar(car);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Автомобили марки " << CarMarkToString(mark) << " не найдены." << endl;
    }
}

// Поиск по ФИО владельца
void FindByOwner(const vector<Car>& cars, const string& name, const string& surname, const string& patronymic) 
{
    bool found = false;
    for (const auto& car : cars) 
    {
        if (car.name == name && car.surname == surname && car.patronymic == patronymic) 
        {
            PrintCar(car);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Автомобиль с владельцем " << name << " " << surname << " " << patronymic << " не найден." << endl;
    }
}

// Интерактивное меню
void Menu(vector<Car>& cars)
{
    int choice;
    do 
    {
        cout << "\n=== Меню ===\n";
        cout << "1. Вывести все автомобили\n";
        cout << "2. Найти по марке\n";
        cout << "3. Найти по владельцу\n";
        cout << "4. Выход\n";
        cout << "Выберите действие (1–4): ";
    } while (choice != 4);
}