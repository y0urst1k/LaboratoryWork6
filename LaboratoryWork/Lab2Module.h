#pragma once
#include "Bell.h"
#include "OddEvenSeparator.h"
#include "Table.h"

class Lab2Module
{
private:
	Bell* bell;
	OddEvenSeparator* separator;
	Table* table;

	void PrintSeparator(char = '-', int = 30);
	void StartEx1();
	void TestEx2();
	void StartEx2();
	void StartEx3();
	void StartEx4();
	void StartEx5();

public:
	void StartLab();
	Lab2Module();
	~Lab2Module();
};