#include "Lab2Module.h"
#include <iostream>

Lab2Module::Lab2Module()
{
	bell = new Bell;
	separator = new OddEvenSeparator;
	table = new Table(3,3);
}

Lab2Module::~Lab2Module()
{
	delete bell;
	delete separator;
	delete table;
	bell = nullptr;
	separator = nullptr;
	table = nullptr;
}

void Lab2Module::StartEx1()
{
	std::cout << "Start ex 1" << std::endl;

	bell->Sound();

	std::cout << "Ex 1 is complete" << std::endl;
}

void Lab2Module::TestEx2()
{
	separator->AddNumber(1);
	separator->AddNumber(2);
	separator->AddNumber(4);
	separator->AddNumber(5);
	separator->AddNumber(3);
	separator->AddNumber(9);
	separator->AddNumber(11);
	separator->AddNumber(16);
	separator->AddNumber(7);
}

void Lab2Module::StartEx2()
{
	std::cout << "Start ex 2" << std::endl;
	
	separator->Even();
	separator->Odd();

	std::cout << "Ex 2 is complete" << std::endl;
}

void Lab2Module::StartEx3()
{
	std::cout << "Start ex 3" << std::endl;

	int value = -1;
	table->FillTable();
	value = table->GetValue(1, 2);
	std::cout << "Value in posotion 1x2: " << value << std::endl;
	table->SetValue(1, 2, 10);
	value = table->GetValue(1, 2);
	std::cout << "New value in posotion 1x2: " << value << std::endl;
	std::cout << "Rows count: " << table->RowsCount() << std::endl;
	std::cout << "Columns count: " << table->ColumnsCount() << std::endl;
	table->Print();
	std::cout << "Average: " << table->Average() << std::endl;

	table->Print(true);

	std::cout << "Ex 3 is complete" << std::endl;
}

void Lab2Module::StartEx4()
{

}

void Lab2Module::StartEx5()
{

}

void Lab2Module::StartLab()
{
	StartEx1();
	StartEx2();
	StartEx3();
}