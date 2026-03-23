#pragma once
class Complex
{
private:
	double re;
	double im;

public:
	Complex();
	Complex(double, double);

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
};

