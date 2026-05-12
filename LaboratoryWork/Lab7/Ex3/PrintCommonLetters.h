#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

void PrintCommonLetters(const std::vector<std::string>& words) 
{
    if (words.empty()) return;

    // Начальное множество — буквы первого слова
    std::set<char> common_letters(words[0].begin(), words[0].end());

    for (size_t i = 1; i < words.size(); ++i) 
    {
        std::set<char> current_letters(words[i].begin(), words[i].end());
        std::set<char> intersection;

        // Находим пересечение двух множеств
        std::set_intersection(
            common_letters.begin(), common_letters.end(),
            current_letters.begin(), current_letters.end(),
            std::inserter(intersection, intersection.begin())
        );

        // Перемещаем результат в common_letters
        common_letters = std::move(intersection);
    }

    // Выводим результат (set уже отсортирован)
    for (char c : common_letters) 
    {
        std::cout << c;
    }
    std::cout << '\n';
}