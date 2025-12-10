#include "Data.h"
#include "MyList.h"
#include "ConvertDataToStr.h"
#include "BusinessLogic.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::endl;
using std::cout;
using std::string;
using std::fstream;
using std::map;
using std::cin;
using std::getline;
using std::ios;

time_t ParseDate(const string& dateStr)
{
    struct tm tm = {};
    int year, month, day;

    if (sscanf_s(dateStr.c_str(), "%d.%d.%d", &day, &month, &year) == 3)
    {
        tm.tm_mday = day;
        tm.tm_mon = month - 1;
        tm.tm_year = year - 1900;
        tm.tm_isdst = -1;         

        return mktime(&tm);
    }
    return 0;
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
    return (it != map.end()) ? it->second : CarMark::Unknown;
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
    return (it != map.end()) ? it->second : CarColor::Unknown;
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
    return (it != map.end()) ? it->second : CarBodywork::Unknown;
}

void PrintCarMarksWithNumbers()
{
    std::cout << "1. MercedesBenz\n"
        << "2. BMW\n"
        << "3. Audi\n"
        << "4. Volkswagen\n"
        << "5. Porsche\n"
        << "6. Opel\n"
        << "7. Toyota\n"
        << "8. Mitsubishi\n"
        << "9. Mazda\n"
        << "10. Lexus\n"
        << "11. Nissan\n"
        << "12. Suzuki\n"
        << "13. Cadillac\n"
        << "14. Dodge\n"
        << "15. Chevrolet\n"
        << "16. Lada\n"
        << "17. УАЗ\n"
        << "18. Aurus\n";
}

CarMark GetCarMarkByNumber(int num)
{

    switch (num)
    {
    case 1:  return CarMark::MercedesBenz;
    case 2:  return CarMark::BMW;
    case 3:  return CarMark::Audi;
    case 4:  return CarMark::Volkswagen;
    case 5:  return CarMark::Porsche;
    case 6:  return CarMark::Opel;
    case 7:  return CarMark::Toyota;
    case 8:  return CarMark::Mitsubishi;
    case 9:  return CarMark::Mazda;
    case 10: return CarMark::Lexus;
    case 11: return CarMark::Nissan;
    case 12: return CarMark::Suzuki;
    case 13: return CarMark::Cadillac;
    case 14: return CarMark::Dodge;
    case 15: return CarMark::Chevrolet;
    case 16: return CarMark::Lada;
    case 17: return CarMark::УАЗ;
    case 18: return CarMark::Aurus;
    default: return CarMark::Unknown;
    }
}

void PrintCarColorsWithNumbers()
{
    std::cout << "1. Blue\n"
        << "2. Red\n"
        << "3. Pink\n"
        << "4. Purple\n"
        << "5. Green\n"
        << "6. Yellow\n"
        << "7. Black\n"
        << "8. White\n"
        << "9. Gray\n";
}

CarColor GetCarColorByNumber(int num)
{
    switch (num)
    {
    case 1:  return CarColor::Blue;
    case 2:  return CarColor::Red;
    case 3:  return CarColor::Pink;
    case 4:  return CarColor::Purple;
    case 5:  return CarColor::Green;
    case 6:  return CarColor::Yellow;
    case 7:  return CarColor::Black;
    case 8:  return CarColor::White;
    case 9:  return CarColor::Gray;
    default: return CarColor::Unknown;
    }
}

void PrintCarBodyworksWithNumbers()
{
    std::cout << "1. Sedan\n"
        << "2. Compartment\n"
        << "3. Hatchback\n"
        << "4. Universal\n";
}

CarBodywork GetCarBodyworkByNumber(int num)
{
    switch (num)
    {
    case 1:  return CarBodywork::Sedan;
    case 2:  return CarBodywork::Compartment;
    case 3:  return CarBodywork::Hatchback;
    case 4:  return CarBodywork::Universal;
    default: return CarBodywork::Unknown;
    }
}

void ReadDataFromFile(MyList& cars, fstream& file)
{
    cars.Clear();

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
            mark = CarMark::Unknown;
        if (colorStr == "Unknown")
            color = CarColor::Unknown;
        if (bodyStr == "Unknown")
            body = CarBodywork::Unknown;

        Car car(mark, color, factorynumber,
            0, 0, 0,
            body, name, surname, patronymic);
        car.releaseDate = releaseDate;
        car.technicalInspectionDate = techInspectionDate;

        cars.PushBack(car);
    }

    if (!file.eof() && file.fail())
    {
        cout << "Ошибка чтения файла!" << endl;
    }
}

void WriteDataInFile(const MyList& cars, fstream& file)
{
    for (Node* ptr = cars.head; ptr != nullptr; ptr = ptr->next)
    {
        file << CarMarkToString(ptr->car.carmark) << " " << CarColorToString(ptr->car.carColor, false) << " "
            << ptr->car.factorynumber << " "
            << ptr->car.releaseDate << " "
            << CarBodyworkToString(ptr->car.carBodywork, false) << " "
            << ptr->car.technicalInspectionDate << " "
            << ptr->car.name << " "
            << ptr->car.surname << " "
            << ptr->car.patronymic << " " << endl;
    }
}

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

void PrintAllCars(const MyList& cars) 
{
    if (cars.IsEmpty()) 
    {
        cout << "Список автомобилей пуст." << endl;
        return;
    }
    for (size_t i = 0; i < cars.Size(); i++) 
    {
        cout << "Автомобиль #" << (i + 1) << ":" << endl;
        PrintCar(cars.GetAt(i)->car);
    }
}

void FindByMark(const MyList& cars, CarMark mark) 
{
    bool found = false;
    for (Node* ptr = cars.head; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->car.carmark == mark) 
        {
            PrintCar(ptr->car);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Автомобили марки " << CarMarkToString(mark) << " не найдены." << endl;
    }
}

void FindByOwner(const MyList& cars, const string& name, const string& surname, const string& patronymic) 
{
    bool found = false;
    for (Node* ptr = cars.head; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->car.name == name && ptr->car.surname == surname && ptr->car.patronymic == patronymic) 
        {
            PrintCar(ptr->car);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Автомобиль с владельцем " << name << " " << surname << " " << patronymic << " не найден." << endl;
    }
}

Car InputCar()
{
    Car car;
    int choice;

    cout << "Выберите марку автомобиля:\n";
    PrintCarMarksWithNumbers();
    while (true) 
    {
        cout << "Введите номер (1–18): ";
        cin >> choice;
        cin.ignore();

        car.carmark = GetCarMarkByNumber(choice);
        if (car.carmark != CarMark::Unknown) 
        {
            break;
        }
        cout << "Неверный номер! Попробуйте снова.\n";
    }

    cout << "\nВыберите цвет автомобиля:\n";
    PrintCarColorsWithNumbers();
    while (true) 
    {
        cout << "Введите номер (1–9): ";
        cin >> choice;
        cin.ignore();

        car.carColor = GetCarColorByNumber(choice);
        if (car.carColor != CarColor::Unknown) 
        {
            break;
        }
        cout << "Неверный номер! Попробуйте снова.\n";
    }

    cout << "\nЗаводской номер: ";
    getline(cin, car.factorynumber);

    string dateStr;
    cout << "Дата выпуска (dd.mm.yyyy): ";
    while (true) 
    {
        getline(cin, dateStr);
        car.releaseDate = ParseDate(dateStr);
        if (car.releaseDate != 0) 
        {
            break;
        }
        cout << "Ошибка формата даты! Используйте дд.мм.гггг. Повторите ввод: ";
    }

    cout << "\nВыберите тип кузова:\n";
    PrintCarBodyworksWithNumbers();
    while (true) 
    {
        cout << "Введите номер (1–4): ";
        cin >> choice;
        cin.ignore();

        car.carBodywork = GetCarBodyworkByNumber(choice);
        if (car.carBodywork != CarBodywork::Unknown) 
        {
            break;
        }
        cout << "Неверный номер! Попробуйте снова.\n";
    }

    cout << "\nИмя владельца: ";
    getline(cin, car.name);
    cout << "Фамилия владельца: ";
    getline(cin, car.surname);
    cout << "Отчество владельца: ";
    getline(cin, car.patronymic);

    // Дата ТО
    cout << "Дата ТО (dd.mm.yyyy): ";
    while (true) 
    {
        getline(cin, dateStr);
        car.technicalInspectionDate = ParseDate(dateStr);
        if (car.technicalInspectionDate != 0) 
        {
            break;
        }
        cout << "Ошибка формата даты! Используйте дд.мм.гггг. Повторите ввод: ";
    }

    return car;
}

void DeleteCarByIndex(MyList& cars)
{
    if (cars.IsEmpty()) 
    {
        cout << "Список пуст, удалять нечего." << endl;
        return;
    }

    int index;
    cout << "Введите номер автомобиля для удаления (от 1 до " << cars.Size() << "): ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > cars.Size()) 
    {
        cout << "Неверный номер!" << endl;
        return;
    }

    cars.Delete(index - 1);
    cout << "Автомобиль удалён." << endl;
}

void ClearCars(MyList& cars)
{
    cars.Clear();
    cout << "Список автомобилей очищен." << endl;
}

void Menu(MyList& cars)
{
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
        cout << "7. Добавить автомобиль\n";
        cout << "8. Удалить автомобиль по номеру\n";
        cout << "9. Очистить список\n";
        cout << "Выберите действие (1–9): ";

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
            case 7: 
            {
                Car car = InputCar();
                cars.PushBack(car);
                cout << "Автомобиль добавлен." << endl;
                break;
            }
            case 8: 
            {
                DeleteCarByIndex(cars);
                break;
            }
            case 9: 
            {
                ClearCars(cars);
                break;
            }
            default: {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
            }
        }
    } while (choice != 6);
}