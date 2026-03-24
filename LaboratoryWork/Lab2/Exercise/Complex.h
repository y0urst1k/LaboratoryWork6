#pragma once
#include <ostream>
#include <istream>
class Complex
{
private:
	double re;
	double im;

public:
	Complex();
	Complex(double, double);
	Complex(const Complex& other);

	void SetRe(double);
	double GetRe() const;
	void SetIm(double);
	double GetIm() const;

	double Abs() const;
	double Arg() const;
	void Print() const;
	void TrigPrint() const;
	void ExpPrint() const;

	Complex Add(const Complex& z) const;
	Complex Sub(const Complex& z) const;
	Complex Mult(const Complex& z) const;
	Complex Div(const Complex& z) const;

	Complex& operator=(const Complex& other);
	Complex operator+(const Complex& other) const;
	Complex operator-(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	Complex operator/(const Complex& other) const;

	Complex& operator--();
	Complex operator--(int);
	Complex& operator++();
	Complex operator++(int);

	bool operator>(const Complex& other) const;
	bool operator<(const Complex& other) const;
	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Complex& z);
	friend std::istream& operator>>(std::istream& is, Complex& z);
};

