#include <iostream>
#include "General.h"

void ClearMatrix(int**& matrix, int n)
{
    if (matrix == nullptr) 
        return;
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    matrix = nullptr;
}

int GetFromInterval(int start, int end)
{
    return rand() % (end - start + 1) + start;
}