#include <iostream>
#include "General.h"
#include "MatrixWork.h"
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void OutputMatrix(int**& matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(5) << matrix[i][j];
        }

        cout << endl;
    }
}

int**& GetMatrix(int size, int start, int end)
{
    int*** matrix_ptr = new int**;
    *matrix_ptr = new int* [size];

    for (int i = 0; i < size; i++)
    {
        (*matrix_ptr)[i] = new int[size];

        for (int j = 0; j < size; j++)
        {
            (*matrix_ptr)[i][j] = GetFromInterval(start, end);
        }
    }

    return *matrix_ptr;
}

int* FindPositiveMinInRed(int**& matrix, int size)
{
    int mid = size / 2;
    int* positiveMin = nullptr;

    for (int i = 0; i <= mid; i++)
    {
        for (int j = size - 1; j >= size - 1 - i; j--)
        {
            // Исключаем элементы по главной и побочным диагоналям
            if (j == i || j == size - 1 - i)
                continue;

            if (matrix[i][j] > 0)
            {
                if (!positiveMin || matrix[i][j] < *positiveMin)
                    positiveMin = &matrix[i][j];
            }
        }
    }

    for (int i = mid + 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (j == i || j == size - 1 - i)
                continue;

            if (matrix[i][j] > 0)
            {
                if (!positiveMin || matrix[i][j] < *positiveMin)
                    positiveMin = &matrix[i][j];
            }
        }
    }

    return positiveMin;
}

int* FindNegativeMaxInGreen(int**& matrix, int size)
{
    int* negativeMax = nullptr;
    bool foundNegative = false;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && i + j < size - 1)
            {
                if (matrix[i][j] < 0)
                {
                    if (!foundNegative || matrix[i][j] > *negativeMax)
                    {
                        negativeMax = &matrix[i][j];
                        foundNegative = true;
                    }
                }
            }
        }
    }

    return negativeMax;
}

void SwapElements(int* negativeMax, int* positiveMin)
{
    if(negativeMax == nullptr || positiveMin == nullptr) 
    {
        return;
    }
    int temp = *negativeMax;
    *negativeMax = *positiveMin;
    *positiveMin = temp;
}

void UseMatrix()
{
    int size, start, end;
    cout << "Введите размер массива" << endl;
    cin >> size;
    cout << "ВВедите интервал для генерации (через пробел)" << endl;
    cin >> start >> end;

    int**& matrix = GetMatrix(size, start, end);

    cout << "Массив: ";
    OutputMatrix(matrix, size);

    cout << endl;

    int* negativeMax = FindNegativeMaxInGreen(matrix, size);
    int* positiveMin = FindPositiveMinInRed(matrix, size);

    cout << "Максимальное отрицательное число: " << *negativeMax << endl;
    cout << "Минимальное положительное число: " << *positiveMin << endl;

    SwapElements(negativeMax, positiveMin);

    cout << "Массив после перемещения этих чисел: ";
    OutputMatrix(matrix, size);

    ClearMatrix(matrix, size);
}