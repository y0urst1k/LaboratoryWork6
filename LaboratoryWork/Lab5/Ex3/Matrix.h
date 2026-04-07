#pragma once
#include <iostream>
#include <vector>
#include <string>

// Предварительное объявление шаблона класса
template<typename T>
class Matrix;

// Предварительные объявления шаблонных операторов
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

template<typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix);

// Определение шаблона класса
template<typename T>
class Matrix
{
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    // Конструкторы
    Matrix(int r, int c);
    Matrix(const Matrix& other);

    // Деструктор
    ~Matrix() = default;

    // Методы доступа
    bool Set(int i, int j, const T& value);
    bool Get(int i, int j, T& result) const;

    // Операторы
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;

    // Размеры матрицы
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Друзья — корректные объявления
    friend std::ostream& operator<<<T>(std::ostream& os, const Matrix<T>& matrix);
    friend std::istream& operator>><T>(std::istream& is, Matrix<T>& matrix);
};

// Реализация методов

template<typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c)
{
    if (r <= 0 || c <= 0)
    {
        std::cout << "Ошибка: размеры матрицы должны быть положительными. Создана матрица 1x1.\n";
        rows = 1;
        cols = 1;
    }
    data.resize(rows, std::vector<T>(cols));
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
    : rows(other.rows), cols(other.cols), data(other.data) {
}

template<typename T>
bool Matrix<T>::Set(int i, int j, const T& value)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        std::cout << "Ошибка: индексы [" << i << "][" << j << "] выходят за границы матрицы "
            << rows << "x" << cols << "\n";
        return false;
    }
    data[i][j] = value;
    return true;
}

template<typename T>
bool Matrix<T>::Get(int i, int j, T& result) const
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        std::cout << "Ошибка: индексы [" << i << "][" << j << "] выходят за границы матрицы "
            << rows << "x" << cols << "\n";
        return false;
    }
    result = data[i][j];
    return true;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        std::cout << "Ошибка: матрицы должны иметь одинаковые размеры для сложения. Возвращена пустая матрица.\n";
        return Matrix<T>(0, 0);
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
    if (cols != other.rows)
    {
        std::cout << "Ошибка: число столбцов первой матрицы (" << cols
            << ") должно равняться числу строк второй (" << other.rows
            << "). Возвращена пустая матрица.\n";
        return Matrix<T>(0, 0);
    }

    int resultRows = rows;
    int resultCols = other.cols;
    Matrix<T> result(resultRows, resultCols);

    for (int i = 0; i < resultRows; ++i)
    {
        for (int j = 0; j < resultCols; ++j)
        {
            T sum{};
            for (int k = 0; k < cols; ++k)
            {
                sum = sum + (data[i][k] * other.data[k][j]);
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Реализация операторов

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    if (matrix.getRows() == 0 || matrix.getCols() == 0)
    {
        os << "Пустая матрица\n";
        return os;
    }
    for (int i = 0; i < matrix.getRows(); ++i)
    {
        for (int j = 0; j < matrix.getCols(); ++j)
        {
            T val;
            if (matrix.Get(i, j, val))
            {
                os << val;
                if (j < matrix.getCols() - 1) os << "\t";
            }
            else
            {
                os << "?";
                if (j < matrix.getCols() - 1) os << "\t";
            }
        }
        os << "\n";
    }
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.getRows(); ++i)
    {
        for (int j = 0; j < matrix.getCols(); ++j)
        {
            T value;
            is >> value;
            matrix.Set(i, j, value);
        }
    }
    return is;
}