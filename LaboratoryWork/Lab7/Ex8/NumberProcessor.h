#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <string>

class NumberProcessor
{
private:
    std::vector<int> data;

public:
    // Загрузка данных
    bool LoadData(const std::string& filename);

    // Пункт a
    void FindNumberAndPositions() const;

    // Пункт b
    void ProcessEvenOdd() const;

    // Пункт c
    void SortAndDisplay() const;

    // Пункт d
    void SwapFirstLast();

    void DisplayData() const;

    // Получение размера вектора
    size_t Size() const { return data.size(); }
};

void ShowMenu(NumberProcessor& processor);