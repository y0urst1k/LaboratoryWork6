#pragma once
#include <ostream>

class Rational
{
private:
    int num;      // числитель
    int denom;    // знаменатель (всегда положительный)

    // вспомогательная функция для приведения дроби к несократимому виду
    void Reduce();

public:
    // конструктор с параметрами по умолчанию
    Rational(int num_ = 0, int denom_ = 1);

    // функции-члены для получения числителя и знаменателя
    int Numerator() const;
    int Denominator() const;

    // унарные операторы
    Rational operator+() const;
    Rational operator-() const;

    // бинарные операторы (работают и с int)
    Rational operator+(const Rational& other) const;
    Rational operator+(int n) const;
    friend Rational operator+(int n, const Rational& r);

    Rational operator-(const Rational& other) const;
    Rational operator-(int n) const;
    friend Rational operator-(int n, const Rational& r);

    Rational operator*(const Rational& other) const;
    Rational operator*(int n) const;
    friend Rational operator*(int n, const Rational& r);

    Rational operator/(const Rational& other) const;
    Rational operator/(int n) const;
    friend Rational operator/(int n, const Rational& r);

    // составные операторы
    Rational& operator+=(const Rational& other);
    Rational& operator+=(int n);

    Rational& operator-=(const Rational& other);;
    Rational& operator-=(int n);;

    Rational& operator*=(const Rational& other);;
    Rational& operator*=(int n);;

    Rational& operator/=(const Rational& other);;
    Rational& operator/=(int n);;

    // операторы сравнения
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    // вывод в поток
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

    bool operator>(const Rational& other) const {
        return num * other.denom > other.num * denom;
    }

    bool operator<(const Rational& other) const {
        return num * other.denom < other.num * denom;
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }
};

