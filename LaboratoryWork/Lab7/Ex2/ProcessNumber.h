#pragma once
#include <iostream>
#include <set>

void ProcessNumbers() 
{
    std::set<int> seen;
    int number;

    while (std::cin >> number) 
    {
        if (seen.find(number) != seen.end())
        {
            std::cout << "YES\n";
        }
        else 
        {
            std::cout << "NO\n";
            seen.insert(number);
        }
    }
}