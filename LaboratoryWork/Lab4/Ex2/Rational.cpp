#include "Rational.h"
#if __cplusplus >= 201703L
#include <numeric>
using std::gcd;
#else
int gcd(int a, int b) 
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
#endif

void Rational::Reduce()
{
    int d = gcd(num, denom);
    num /= d;
    denom /= d;
    // обеспечиваем положительный знаменатель
    if (denom < 0) 
    {
        num *= -1;
        denom *= -1;
    }
}

Rational::Rational(int num_, int denom_) : num(num_), denom(denom_) 
{
    if (denom_ == 0) 
    {
        num = 0;
        denom = 1;
    }
    Reduce(); // приводим дробь к несократимому виду
}

// функции-члены для получения числителя и знаменателя
int Rational::Numerator() const { return num; }

int Rational::Denominator() const { return denom; }

// унарные операторы
Rational Rational::operator+() const { return *this; }

Rational Rational::operator-() const { return Rational(-num, denom); }

// бинарные операторы (работают и с int)
Rational Rational::operator+(const Rational& other) const 
{
    return Rational(num * other.denom + other.num * denom, denom * other.denom);
}

Rational Rational::operator+(int n) const { return Rational(num + n * denom, denom); }

Rational operator+(int n, const Rational& r) { return r + n; }

Rational Rational::operator-(const Rational& other) const
{
    return Rational(num * other.denom - other.num * denom, denom * other.denom);
}

Rational Rational::operator-(int n) const { return Rational(num - n * denom, denom); }

Rational operator-(int n, const Rational& r) { return Rational(n * r.denom - r.num, r.denom); }

Rational Rational::operator*(const Rational& other) const
{
    return Rational(num * other.num, denom * other.denom);
}

Rational Rational::operator*(int n) const { return Rational(num * n, denom); }

Rational operator*(int n, const Rational& r) { return r * n; }

Rational Rational::operator/(const Rational& other) const
{
    if (other.num == 0)
    {
        return Rational(0, 1);;
    }
    return Rational(num * other.denom, denom * other.num);
}
Rational Rational::operator/(int n) const
{
    if (n == 0) 
    {
        return Rational(0, 1);
    }
    return Rational(num, denom * n);
}

Rational operator/(int n, const Rational& r)
{
    if (r.num == 0)
    {
        return Rational(0, 1);
    }
    return Rational(n * r.denom, r.num);
}

// составные операторы
Rational& Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    Reduce();
    return *this;
}
Rational& Rational::operator+=(int n)
{
    *this = *this + n;
    Reduce();
    return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    Reduce();
    return *this;
}

Rational& Rational::operator-=(int n)
{
    *this = *this - n;
    Reduce();
    return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    Reduce();
    return *this;
}

Rational& Rational::operator*=(int n)
{
    *this = *this * n;
    Reduce();
    return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    Reduce();
    return *this;
}

Rational& Rational::operator/=(int n)
{
    *this = *this / n;
    Reduce();
    return *this;
}

// операторы сравнения
bool Rational::operator==(const Rational& other) const
{
    return (num == other.num && denom == other.denom);
}

bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

// вывод в поток
std::ostream& operator<<(std::ostream& os, const Rational& r) 
{
    os << r.num << "/" << r.denom;
    return os;
}