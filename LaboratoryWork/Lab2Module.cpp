#include "Lab2Module.h"
#include <iostream>

Lab2Module::Lab2Module()
{
	bell = new Bell;
	separator = new OddEvenSeparator;
}

Lab2Module::~Lab2Module()
{
	delete bell;
	delete separator;
	bell = nullptr;
	separator = nullptr;
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
}