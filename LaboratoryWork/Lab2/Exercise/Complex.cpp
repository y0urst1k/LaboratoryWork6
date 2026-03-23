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
	return Complex(re + z.GetRe(), im + GetIm());
}

Complex Complex::Sub(const Complex& z) const
{
	return Complex(re - z.GetRe(), im - GetIm());
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