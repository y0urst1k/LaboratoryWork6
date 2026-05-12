#pragma once

template <typename Iter>
Iter Unique(Iter first, Iter last) 
{
    // Если диапазон пуст или содержит один элемент — возвращаем last
    if (first == last) 
    {
        return last;
    }

    Iter result = first;  // Итератор для записи уникальных элементов
    ++first;           // Начинаем со второго элемента

    while (first != last) 
    {
        // Если текущий элемент не равен предыдущему уникальному элементу
        if (*first != *result) 
        {
            // Перемещаем уникальный элемент в позицию result + 1
            ++result;
            *result = *first;
        }
        ++first;  // Переходим к следующему элементу
    }

    // Возвращаем итератор за последний уникальный элемент
    return ++result;
}