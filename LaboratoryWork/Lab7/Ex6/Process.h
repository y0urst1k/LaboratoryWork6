#pragma once

#include <algorithm>
#include <vector>
#include <iterator>

template <typename Iter>
void PrintResults(Iter first, Iter last)
{
    for (Iter it = first; it != last; ++it)
        std::cout << *it << std::endl;
}

template <typename T>
void Process(const std::vector<T>& data) 
{
    std::vector<T> filtered;

    auto filteredLast = std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered), // автоматически вызывает push_back
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end()); // передаём весь вектор
}