#include "Contains.h"
#include <string>
#include <iostream>

template<typename T>
bool contains(T element, T* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (element == arr[i])
			return true;
	}

	return false;
}

template<typename T>
bool change(T elem1, T elem2, T* arr, int size)
{
    // Проверяем наличие обоих элементов в массиве
    if (!contains(elem1, arr, size))
    {
        std::cout << "Ошибка: элемент '" << elem1 << "' не найден в массиве!\n";
        return false;
    }

    if (!contains(elem2, arr, size))
    {
        std::cout << "Ошибка: элемент '" << elem2 << "' не найден в массиве!\n";
        return false;
    }

    // Находим индексы элементов
    int index1 = -1, index2 = -1;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == elem1 && index1 == -1)
            index1 = i;
        else if (arr[i] == elem2 && index2 == -1)
            index2 = i;
    }

    // Меняем элементы местами
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;

    std::cout << "Успешно: элементы '" << elem1 << "' и '" << elem2
        << "' поменяны местами!\n";
    return true;
}

template bool contains<int>(int, int*, int);
template bool contains<double>(double, double*, int);
template bool contains<std::string>(std::string, std::string*, int);

template bool change<int>(int, int, int*, int);
template bool change<double>(double, double, double*, int);
template bool change<std::string>(std::string, std::string, std::string*, int);