#pragma once

#include <iostream>
#include <string>

template <typename Container>
void Print(const Container& container, const std::string& delimiter) 
{
    bool is_first = true;

    for (const auto& element : container) 
    {
        if (!is_first) 
        {
            std::cout << delimiter;
        }
        std::cout << element;
        is_first = false;
    }

    std::cout << '\n';
}