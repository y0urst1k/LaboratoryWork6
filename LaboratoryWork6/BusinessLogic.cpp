#include "Data.h"
#include "ConvertDataToStr.h"
#include "BusinessLogic.h"
#include <iostream>
#include <vector>
#include <fstream>

using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::fstream;
using std::map;
using std::cin;
using std::getline;
using std::ios;

void PrintCar(const Car& car) 
{
    cout << "Марка: " << CarMarkToString(car.carmark) << endl;
    cout << "Страна-производитель: " << CountryToString(modelToCountry.at(car.carmark)) << endl;
    cout << "Цвет: " << CarColorToString(car.carColor) << endl;
    cout << "Заводской номер: " << car.factorynumber << endl;

    char buf[100];
    struct tm timeInfo;
    if (localtime_s(&timeInfo, &car.releaseDate) != 0) {
        cout << "Дата выпуска: ошибка преобразования" << endl;
    }
    else {
        strftime(buf, sizeof(buf), "%d.%m.%Y", &timeInfo);
        cout << "Дата выпуска: " << buf << endl;
    }

    if (localtime_s(&timeInfo, &car.technicalInspectionDate) != 0) {
        cout << "Дата ТО: ошибка преобразования" << endl;
    }
    else {
        strftime(buf, sizeof(buf), "%d.%m.%Y", &timeInfo);
        cout << "Дата ТО: " << buf << endl;
    }

    cout << "Кузов: " << CarBodyworkToString(car.carBodywork) << endl;
    cout << "Владелец: " << car.name << " " << car.surname << " " << car.patronymic << endl;
    cout << "----------------------------------------" << endl;
}

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

void Menu(vector<Car>& cars)
{
    InitializeCars(cars);
    int choice;
    do 
    {
        cout << "\n=== Меню ===\n";
        cout << "1. Вывести все автомобили\n";
        cout << "2. Найти по марке\n";
        cout << "3. Найти по владельцу\n";
        cout << "4. Сохранить в файл\n";
        cout << "5. Загрузить из файла\n";
        cout << "6. Выход\n";
        cout << "Выберите действие (1–6): ";

        cin >> choice;
        cin.ignore(); // Очищаем буфер ввода

        switch (choice) 
        {
            case 1: 
            {
                PrintAllCars(cars);
                break;
            }
            case 2: 
            {
                string markStr;
                cout << "Введите марку автомобиля: ";
                getline(cin, markStr);
    
                CarMark mark = CarMarkFromString(markStr);
                if (mark == CarMark::MercedesBenz && markStr != "MercedesBenz") 
                {
                    cout << "Марка не найдена!" << endl;
                }
                else 
                {
                    FindByMark(cars, mark);
                }
                break;
            }
            case 3: 
            {
                string name, surname, patronymic;
                cout << "Имя: "; getline(cin, name);
                cout << "Фамилия: "; getline(cin, surname);
                cout << "Отчество: "; getline(cin, patronymic);
                FindByOwner(cars, name, surname, patronymic);
                break;
            }
            case 4: 
            {
                string filename;
                cout << "Введите имя файла для сохранения: ";
                getline(cin, filename);
    
                fstream file(filename, ios::out);
                if (file.is_open()) 
                {
                    WriteDataInFile(cars, file);
                    file.close();
                    cout << "Данные сохранены в файл " << filename << endl;
                }
                else 
                {
                    cout << "Ошибка открытия файла для записи!" << endl;
                }
                break;
            }
            case 5: 
            {
                string filename;
                cout << "Введите имя файла для загрузки: ";
                getline(cin, filename);

                fstream file(filename, ios::in);
                if (file.is_open()) 
                {
                    ReadDataFromFile(cars, file);
                    file.close();
                    cout << "Данные загружены из файла " << filename << endl;
                }
                else 
                {
                    cout << "Ошибка открытия файла для чтения!" << endl;
                }
                break;
            }
            case 6: 
            {
                cout << "До свидания!" << endl;
                break;
            }
            default: 
            {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
            }
        }
    } while (choice != 6);
}

void WriteDataInFile(const vector<Car>& cars, fstream& file)
{
    for (const auto& car : cars)
    {
        file << CarMarkToString(car.carmark) << " " << CarColorToString(car.carColor, false) << " "
            << car.factorynumber << " "
            << car.releaseDate << " "
            << CarBodyworkToString(car.carBodywork, false) << " "
            << car.technicalInspectionDate << " "
            << car.name << " "
            << car.surname << " "
            << car.patronymic << " " << endl;
    }
}

void ReadDataFromFile(vector<Car>& cars, fstream& file)
{
    cars.clear();

    string markStr, colorStr, bodyStr;
    string factorynumber, name, surname, patronymic;
    time_t releaseDate, techInspectionDate;

    while (file >> markStr >> colorStr >> factorynumber
        >> releaseDate >> bodyStr >> techInspectionDate
        >> name >> surname >> patronymic) 
    {
        CarMark mark = CarMarkFromString(markStr);
        CarColor color = CarColorFromString(colorStr);
        CarBodywork body = CarBodyworkFromString(bodyStr);

        if (markStr == "Unknown")
            mark = CarMark::MercedesBenz;
        if (colorStr == "Unknown")
            color = CarColor::Blue;
        if (bodyStr == "Unknown")
            body = CarBodywork::Sedan;

        Car car(mark, color, factorynumber,
            0, 0, 0,
            body, name, surname, patronymic);
        car.releaseDate = releaseDate;
        car.technicalInspectionDate = techInspectionDate;

        cars.push_back(car);
    }

    if (!file.eof() && file.fail()) 
    {
        cout << "Ошибка чтения файла!" << endl;
    }
}

CarMark CarMarkFromString(const string& str) 
{
    static const map<string, CarMark> map = 
    {
        {"MercedesBenz", CarMark::MercedesBenz},
        {"BMW", CarMark::BMW},
        {"Audi", CarMark::Audi},
        {"Volkswagen", CarMark::Volkswagen}, 
        {"Porsche", CarMark::Porsche}, 
        {"Opel", CarMark::Opel},
        {"Toyota", CarMark::Toyota}, 
        {"Mitsubishi", CarMark::Mitsubishi}, 
        {"Mazda", CarMark::Mazda}, 
        {"Lexus", CarMark::Lexus}, 
        {"Nissan", CarMark::Nissan}, 
        {"Suzuki", CarMark::Suzuki},
        {"Cadillac", CarMark::Cadillac}, 
        {"Dodge", CarMark::Dodge}, 
        {"Chevrolet", CarMark::Chevrolet},
        {"Lada", CarMark::Lada}, 
        {"УАЗ", CarMark::УАЗ}, 
        {"Aurus", CarMark::Aurus}
    };
    auto it = map.find(str);
    return (it != map.end()) ? it->second : CarMark::MercedesBenz;
}

CarColor CarColorFromString(const string& str) 
{
    static const map<string, CarColor> map =
    {
        {"Blue", CarColor::Blue},
        {"Red", CarColor::Red},
        {"Pink", CarColor::Pink},
        { "Purple", CarColor::Purple},
        { "Green", CarColor::Green},
        {"Yellow", CarColor::Yellow},
        {"Black", CarColor::Black},
        {"White", CarColor::White},
        {"Gray", CarColor::Gray}
    };
    auto it = map.find(str);
    return (it != map.end()) ? it->second : CarColor::Blue;
}

CarBodywork CarBodyworkFromString(const string& str) 
{
    static const map<string, CarBodywork> map = 
    {
        {"Sedan", CarBodywork::Sedan},
        {"Compartment", CarBodywork::Compartment},
        {"Hatchback", CarBodywork::Hatchback},
        {"Universal", CarBodywork::Universal}
    };
    auto it = map.find(str);
    return (it != map.end()) ? it->second : CarBodywork::Sedan;
}

void InitializeCars(vector<Car>& cars) 
{
    cars.clear();

    cars.emplace_back(
        CarMark::BMW,
        CarColor::Blue,
        "WBA123456789",
        2023, 1, 15,
        CarBodywork::Sedan,
        "Иван",
        "Иванов",
        "Иванович"
    );

    cars.emplace_back(
        CarMark::Audi,
        CarColor::Red,
        "WAU987654321",
        2024, 5, 20,
        CarBodywork::Hatchback,
        "Пётр",
        "Петров",
        "Петрович"
    );

    cars.emplace_back(
        CarMark::MercedesBenz,
        CarColor::Black,
        "WDD111222333",
        2022, 11, 10,
        CarBodywork::Compartment,
        "Анна",
        "Сидорова",
        "Сергеевна"
    );

    cars.emplace_back(
        CarMark::Toyota,
        CarColor::White,
        "JT123456789012345",
        2021, 3, 25,
        CarBodywork::Universal,
        "Алексей",
        "Смирнов",
        "Дмитриевич"
    );

    cars.emplace_back(
        CarMark::Lada,
        CarColor::Gray,
        "XTA12345678901234",
        2020, 7, 12,
        CarBodywork::Hatchback,
        "Мария",
        "Кузнецова",
        "Александровна"
    );

    cars.emplace_back(
        CarMark::Porsche,
        CarColor::Yellow,
        "WP0ZZZ99ZPLA12345",
        2025, 2, 8,
        CarBodywork::Compartment,
        "Дмитрий",
        "Морозов",
        "Владимирович"
    );

    cars.emplace_back(
        CarMark::Volkswagen,
        CarColor::Green,
        "WV123456789012345",
        2019, 9, 18,
        CarBodywork::Sedan,
        "Елена",
        "Фёдорова",
        "Михайловна"
    );

    cars.emplace_back(
        CarMark::Mitsubishi,
        CarColor::Pink,
        "JA323456789012345",
        2022, 4, 30,
        CarBodywork::Universal,
        "Сергей",
        "Соколов",
        "Николаевич"
    );

    cars.emplace_back(
        CarMark::Nissan,
        CarColor::Purple,
        "JN123456789012345",
        2021, 6, 14,
        CarBodywork::Hatchback,
        "Ольга",
        "Васильева",
        "Игоревна"
    );

    cars.emplace_back(
        CarMark::Chevrolet,
        CarColor::Blue,
        "1G123456789012345",
        2023, 8, 22,
        CarBodywork::Sedan,
        "Андрей",
        "Павлов",
        "Константинович"
    );

    cars.emplace_back(
        CarMark::Aurus,
        CarColor::Red,
        "1G123456789012349",
        2021, 8, 22,
        CarBodywork::Sedan,
        "Василий",
        "Котиков",
        "Константинович"
    );

    cout << "Вектор заполнен тестовыми данными (" << cars.size() << " автомобилей)" << endl;
}