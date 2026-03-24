#include "Complex.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

Complex::Complex()
{
	re = 0;
	im = 0;
}

Complex::Complex(double xRe, double yMi)
{
	re = xRe;
	im = yMi;
}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

void Complex::SetRe(double value)
{
	re = value;
}

double Complex::GetRe() const
{
	return re;
}

void Complex::SetIm(double value)
{
	im = value;
}

double Complex::GetIm() const
{
	return im;
}

double Complex::Abs() const
{
	return sqrt(re * re + im * im);
}

double Complex::Arg() const
{
	double result = 0;

	if (re > 0)
		result = atan(im / re);

	if (im > 0 && re < 0)
		result = M_PI + atan(im / re);

	if (im < 0)
		result = -M_PI + atan(im / re);

	return result;
}

void Complex::Print() const
{
	if (im < 0)
		std::cout << re << im << "i" << std::endl;
	else
		std::cout << re << "+" << im << "i" << std::endl;
}

void Complex::TrigPrint() const
{
	double phi = Arg();
	std::cout << Abs() << "(" << "cos(" << phi << ")+isin(" << phi << "))" << std::endl;
}

void Complex::ExpPrint() const
{
	if (im < 0)
		std::cout << Abs() << "e^(i(" << Arg() << "))" << std::endl;
	else
		std::cout << Abs() << "e^(i" << Arg() << ")" << std::endl;
}

Complex Complex::Add(const Complex& z) const
{
	return Complex(re + z.GetRe(), im + z.GetIm());
}

Complex Complex::Sub(const Complex& z) const
{
	return Complex(re - z.GetRe(), im - z.GetIm());
}

Complex Complex::Mult(const Complex& z) const
{
	double zRe = z.GetRe();
	double zIm = z.GetIm();
	return Complex(re * zRe - im * zIm, im * zRe + re * zIm);
}

Complex Complex::Div(const Complex& z) const
{
	double zRe = z.GetRe();
	double zIm = z.GetIm();
	double partRe = (re * zRe + im * zIm) / (zRe*zRe + zIm*zIm);
	double partIm = (im * zRe - re * zIm) / (zRe*zRe + zIm*zIm);
	return Complex(partRe, partIm);
}

Complex& Complex::operator=(const Complex& other) 
{
	if (this != &other)  // защита от самоприсваивания
	{
		re = other.re;
		im = other.im;
	}
	return *this;
}

Complex Complex::operator+(const Complex& other) const 
{
	return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const 
{
	return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const
{
	double newRe = re * other.re - im * other.im;
	double newIm = im * other.re + re * other.im;
	return Complex(newRe, newIm);
}

Complex Complex::operator/(const Complex& other) const 
{
	double denom = other.re * other.re + other.im * other.im;
	double newRe = (re * other.re + im * other.im) / denom;
	double newIm = (im * other.re - re * other.im) / denom;
	return Complex(newRe, newIm);
}

Complex& Complex::operator--() 
{
	re -= 1;
	im -= 1;
	return *this;
}

Complex Complex::operator--(int) 
{
	Complex copy(*this);
	--(*this);
	return copy;
}

Complex& Complex::operator++()
{
	re += 1;
	im += 1;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex copy(*this);
	++(*this);
	return copy;
}

bool Complex::operator>(const Complex& other) const 
{
	return Abs() > other.Abs();
}

bool Complex::operator<(const Complex& other) const 
{
	return Abs() < other.Abs();
}

bool Complex::operator==(const Complex& other) const 
{
	return Abs() == other.Abs();
}

bool Complex::operator!=(const Complex& other) const 
{
	return Abs() != other.Abs();
}

std::ostream& operator<<(std::ostream& os, const Complex& z) 
{
	os << z.re << " + " << z.im << "*i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& z) 
{
	is >> z.re >> z.im;
	return is;
}