#pragma once
#include <vector>
#include <iostream>

// Предварительное объявление шаблона класса
template<typename T>
class Polynomial;

// Предварительные объявления шаблонных операторов
template<typename T>
std::ostream& operator<<(std::ostream& os, const Polynomial<T>& poly);

template<typename T>
class Polynomial
{
private:
    std::vector<T> coefficients; // Коэффициенты по возрастанию степени

    // Вспомогательная функция для удаления ведущих нулей
    void RemoveLeadingZeros();

public:
    // Конструкторы
    Polynomial();
    Polynomial(const std::vector<T>& coeffs);
    Polynomial(const T& scalar);

    // Операторы сравнения
    bool operator==(const Polynomial<T>& other) const;
    bool operator!=(const Polynomial<T>& other) const;
    bool operator==(const T& scalar) const;
    bool operator!=(const T& scalar) const;

    // Арифметические операторы
    Polynomial<T> operator+(const Polynomial<T>& other) const;
    Polynomial<T> operator-(const Polynomial<T>& other) const;
    Polynomial<T> operator*(const Polynomial<T>& other) const;

    Polynomial<T>& operator+=(const Polynomial<T>& other);
    Polynomial<T>& operator-=(const Polynomial<T>& other);
    Polynomial<T>& operator*=(const Polynomial<T>& other);

    // Операторы со скаляром
    Polynomial<T> operator+(const T& scalar) const;
    Polynomial<T> operator-(const T& scalar) const;
    Polynomial<T> operator*(const T& scalar) const;

    Polynomial<T>& operator+=(const T& scalar);
    Polynomial<T>& operator-=(const T& scalar);
    Polynomial<T>& operator*=(const T& scalar);

    // Доступ к коэффициентам
    const T& operator[](int degree) const;

    // Степень многочлена
    int Degree() const;

    // Вычисление значения в точке
    T operator()(const T& x) const;

    // Друзья — корректные объявления
    friend std::ostream& operator<<<T>(std::ostream& os, const Polynomial<T>& poly);
};

// Реализация методов

template<typename T>
void Polynomial<T>::RemoveLeadingZeros()
{
    while (coefficients.size() > 1 && coefficients.back() == T())
    {
        coefficients.pop_back();
    }
}

// Конструктор по умолчанию (нулевой многочлен)
template<typename T>
Polynomial<T>::Polynomial() : coefficients(1, T()) {}

// Конструктор из вектора коэффициентов
template<typename T>
Polynomial<T>::Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs)
{
    RemoveLeadingZeros();
}

// Конструктор из скаляра (многочлен нулевой степени)
template<typename T>
Polynomial<T>::Polynomial(const T& scalar) : coefficients(1, scalar) {}

// Операторы сравнения
template<typename T>
bool Polynomial<T>::operator==(const Polynomial<T>& other) const
{
    return coefficients == other.coefficients;
}

template<typename T>
bool Polynomial<T>::operator!=(const Polynomial<T>& other) const
{
    return !(*this == other);
}

template<typename T>
bool Polynomial<T>::operator==(const T& scalar) const
{
    return Degree() == 0 && coefficients[0] == scalar;
}

template<typename T>
bool Polynomial<T>::operator!=(const T& scalar) const
{
    return !(*this == scalar);
}

// Оператор доступа к коэффициенту
template<typename T>
const T& Polynomial<T>::operator[](int degree) const
{
    if (degree < 0)
        return T();
    if (degree >= static_cast<int>(coefficients.size()))
        return T();
    return coefficients[degree];
}

// Степень многочлена
template<typename T>
int Polynomial<T>::Degree() const
{
    if (coefficients.empty())
        return -1;
    if (coefficients.size() == 1 && coefficients[0] == T())
        return -1;
    return static_cast<int>(coefficients.size()) - 1;
}

// Вычисление значения многочлена в точке
template<typename T>
T Polynomial<T>::operator()(const T& x) const
{
    if (Degree() == -1)
        return T();
    T result = coefficients.back();
    for (int i = Degree() - 1; i >= 0; --i)
    {
        result = result * x + coefficients[i];
    }
    return result;
}

// Арифметические операторы
template<typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const
{
    size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
    std::vector<T> result(maxSize, T());

    for (size_t i = 0; i < coefficients.size(); ++i) result[i] = coefficients[i];
    for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] += other.coefficients[i];

    return Polynomial<T>(result);
}

template<typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& other) const
{
    size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
    std::vector<T> result(maxSize, T());

    for (size_t i = 0; i < coefficients.size(); ++i) result[i] = coefficients[i];
    for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] -= other.coefficients[i];

    return Polynomial<T>(result);
}

template<typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& other) const
{
    if (Degree() == -1 || other.Degree() == -1) return Polynomial<T>();

    size_t newSize = coefficients.size() + other.coefficients.size() - 1;
    std::vector<T> result(newSize, T());

    for (size_t i = 0; i < coefficients.size(); ++i)
    {
        for (size_t j = 0; j < other.coefficients.size(); ++j)
        {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial<T>(result);
}

// Составные операторы
template<typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& other)
{
    *this = *this + other;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial<T>& other)
{
    *this = *this - other;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial<T>& other)
{
    *this = *this * other;
    return *this;
}

// Операторы со скалярами
template<typename T>
Polynomial<T> Polynomial<T>::operator+(const T& scalar) const
{
    Polynomial<T> result = *this;
    result.coefficients[0] += scalar;
    return result;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator-(const T& scalar) const
{
    Polynomial<T> result = *this;
    result.coefficients[0] -= scalar;
    return result;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator*(const T& scalar) const
{
    std::vector<T> result = coefficients;
    for (auto& coeff : result) coeff *= scalar;
    return Polynomial<T>(result);
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator+=(const T& scalar)
{
    coefficients[0] += scalar;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-=(const T& scalar)
{
    coefficients[0] -= scalar;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator*=(const T& scalar)
{
    for (auto& coeff : coefficients) {
        coeff *= scalar;
    }
    RemoveLeadingZeros(); // Обновляем после умножения
    return *this;
}

// Оператор вывода в поток
template<typename T>
std::ostream& operator<<(std::ostream& os, const Polynomial<T>& poly)
{
    if (poly.Degree() == -1) {
        os << "0";
        return os;
    }

    bool firstTerm = true;

    // Выводим коэффициенты от старшей степени к младшей
    for (int i = poly.Degree(); i >= 0; --i) {
        const T& coeff = poly[i];

        // Пропускаем нулевые коэффициенты
        if (coeff == T()) {
            continue;
        }

        // Обрабатываем знак
        if (!firstTerm) {
            if (coeff > T()) {
                os << " + ";
            }
            else {
                os << " - ";
            }
        }
        else {
            // Первый член — отрицательный коэффициент требует знака
            if (coeff < T()) {
                os << "-";
            }
            firstTerm = false;
        }

        // Выводим абсолютное значение коэффициента
        T absCoeff = (coeff < T()) ? -coeff : coeff;

        // Для коэффициента 1 или -1 не выводим 1 (кроме случая нулевой степени)
        if (!(absCoeff == T(1) && i > 0)) {
            os << absCoeff;
        }

        // Добавляем переменную и степень
        if (i > 0) {
            os << "x";
            if (i > 1) {
                os << "^" << i;
            }
        }
    }

    return os;
}