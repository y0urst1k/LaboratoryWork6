#include "Lab7Module.h"

#include "Ex1/PrintT.h"
#include "Ex2/ProcessNumber.h"
#include "Ex3/PrintCommonLetters.h"
#include "Ex5/Duplicate.h"
#include "Ex6/Process.h"
#include "Ex7/UniqueT.h"
#include "Ex8/NumberProcessor.h"

#include <vector>
#include <map>
#include <list>
#include <string>

void Lab7Module::StartEx1()
{
    std::vector<int> data1 = { 1, 2, 3 };
    Print(data1, ", ");  // Вывод: 1, 2, 3

    // Пример со списком строк
    std::list<std::string> data2 = { "apple", "banana", "cherry" };
    Print(data2, " | ");  // Вывод: apple | banana | cherry

    // Пример с массивом
    int data3[] = { 10, 20, 30, 40 };
    Print(data3, " -> ");  // Вывод: 10 -> 20 -> 30 -> 40
}

void Lab7Module::StartEx2()
{
    ProcessNumbers();
}

void Lab7Module::StartEx3()
{
    // Пример 1
    std::vector<std::string> words1 = { "apple", "peach" };
    PrintCommonLetters(words1); // Вывод: aep

    // Пример 2
    std::vector<std::string> words2 = { "alpha", "beta", "gamma" };
    PrintCommonLetters(words2); // Вывод: a
}

void Lab7Module::StartEx4()
{
    std::map<std::string, int> word_count;
    std::string word;

    while (std::cin >> word) 
    {
        if (word == "stop") 
        {
            break; // Выход из цикла при вводе стоп‑слова
        }
        // Увеличиваем счётчик для слова и сразу выводим его значение
        std::cout << ++word_count[word] << '\n';
    }
}

void Lab7Module::StartEx5()
{
    std::vector<int> data = { 1, 2, 3 };
    Duplicate(data);

    for (int x : data) 
    {
        std::cout << x << " ";
    }
}

void Lab7Module::StartEx6()
{
    std::vector<int> data = { -1, 2, -3, 4, -5, 6, -7, 8, -9 };
    Process(data);
}

void Lab7Module::StartEx7()
{
    std::vector<int> data = { 1, 1, 2, 2, 3, 3, 4 };

    auto new_end = Unique(data.begin(), data.end());

    // Печатаем только уникальные элементы
    for (auto it = data.begin(); it != new_end; ++it) 
    {
        std::cout << *it << " ";
    }
}

void Lab7Module::StartEx8()
{
    NumberProcessor processor;

    // Попытка загрузить данные при старте
    if (!processor.LoadData("input.txt")) 
    {
        std::cerr << "Предупреждение: не удалось загрузить данные из input.txt\n";
        std::cerr << "Используйте пункт меню 6 для загрузки данных.\n";
    }
    else 
    {
        std::cout << "Данные из input.txt успешно загружены!\n";
    }

    // Запуск меню
    ShowMenu(processor);
}

void Lab7Module::StartLab()
{
    std::cout << "Start ex 1" << std::endl;
    StartEx1();
    std::cout << "End ex 1" << std::endl;

    std::cout << "Start ex 2" << std::endl;
    StartEx2();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "End ex 2" << std::endl;

    std::cout << "Start ex 3" << std::endl;
    StartEx3();
    std::cout << "End ex 3" << std::endl;

    std::cout << "Start ex 4" << std::endl;
    StartEx4();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "End ex 4" << std::endl;

    std::cout << "Start ex 5" << std::endl;
    StartEx5();
    std::cout << "End ex 5" << std::endl;

    std::cout << "Start ex 6" << std::endl;
    StartEx6();
    std::cout << "End ex 6" << std::endl;

    std::cout << "Start ex 7" << std::endl;
    StartEx7();
    std::cout << "End ex 7" << std::endl;

    std::cout << "Start ex 8" << std::endl;
    StartEx8();
    std::cout << "End ex 8" << std::endl;
}