#include "NumberProcessor.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <string>

// Загрузка данных
bool NumberProcessor::LoadData(const std::string& filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) return false;

    int number;
    while (inputFile >> number)
    {
        data.push_back(number);
    }
    inputFile.close();
    return true;
}

// Пункт a
void NumberProcessor::FindNumberAndPositions() const
{
    int n;
    std::cout << "Введите число n для поиска: ";
    std::cin >> n;

    int count_n = std::count(data.begin(), data.end(), n);
    std::cout << "\na. Число " << n << " встречается " << count_n << " раз(а)\n";

    std::cout << "Позиции числа " << n << ": ";
    auto it = data.begin();
    int pos = 0;
    while ((it = std::find(it, data.end(), n)) != data.end())
    {
        std::cout << pos << " ";
        ++it;
        ++pos;
    }
    std::cout << "\n";
}

// Пункт b
void NumberProcessor::ProcessEvenOdd() const
{
    auto is_even = [](int x) { return x % 2 == 0; };
    int even_count = std::count_if(data.begin(), data.end(), is_even);
    int odd_count = data.size() - even_count;

    std::cout << "\nb. Количество чётных элементов: " << even_count << "\n";
    std::cout << "Номера чётных элементов: ";

    int pos = 0;
    for (auto elem : data)
    {
        if (is_even(elem))
        {
            std::cout << pos << " ";
        }
        ++pos;
    }
    std::cout << "\n";

    long long sum_result;
    if (even_count > odd_count)
    {
        sum_result = std::accumulate(data.begin(), data.end(), 0LL,
            [is_even](long long sum, int x)
            {
                return is_even(x) ? sum + x : sum;
            });
        std::cout << "Сумма чётных элементов: " << sum_result << "\n";
    }
    else
    {
        sum_result = std::accumulate(data.begin(), data.end(), 0LL);
        std::cout << "Сумма всех элементов: " << sum_result << "\n";
    }
}

// Пункт c
void NumberProcessor::SortAndDisplay() const
{
    std::vector<int> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());

    std::cout << "\nc. Исходный набор данных: ";
    for (int x : data) std::cout << x << " ";
    std::cout << "\nОтсортированный набор данных: ";
    for (int x : sorted_data) std::cout << x << " ";
    std::cout << "\n";
}

// Пункт d
void NumberProcessor::SwapFirstLast()
{
    if (!data.empty())
    {
        std::swap(data.front(), data.back());
        std::cout << "\nd. Вектор после перестановки первого и последнего элементов: ";
        for (int x : data) std::cout << x << " ";
        std::cout << "\n";
    }
    else
    {
        std::cout << "\nd. Вектор пуст, перестановка невозможна.\n";
    }
}

void NumberProcessor::DisplayData() const
{
    std::cout << "Текущий вектор: ";
    for (int x : data) std::cout << x << " ";
    std::cout << "\n";
}

void ShowMenu(NumberProcessor& processor)
{
    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "\n=== МЕНЮ ===\n";
        std::cout << "1. Показать текущий вектор\n";
        std::cout << "2. Найти число n и его позиции (пункт a)\n";
        std::cout << "3. Обработать чётные/нечётные элементы (пункт b)\n";
        std::cout << "4. Отсортировать и показать данные (пункт c)\n";
        std::cout << "5. Поменять первый и последний элементы (пункт d)\n";
        std::cout << "6. Загрузить новые данные из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            processor.DisplayData();
            break;
        case 2:
            processor.FindNumberAndPositions();
            break;
        case 3:
            processor.ProcessEvenOdd();
            break;
        case 4:
            processor.SortAndDisplay();
            break;
        case 5:
            processor.SwapFirstLast();
            break;
        case 6:
        {
            std::string filename;
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            if (processor.LoadData(filename))
            {
                std::cout << "Данные успешно загружены!\n";
            }
            else
            {
                std::cerr << "Ошибка загрузки данных из файла " << filename << "\n";
            }
            break;
        }
        case 0:
            running = false;
            std::cout << "До свидания!\n";
            break;
        default:
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }
}