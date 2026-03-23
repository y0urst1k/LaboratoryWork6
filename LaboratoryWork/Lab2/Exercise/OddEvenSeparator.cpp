#include "OddEvenSeparator.h"
#include <iostream>

void OddEvenSeparator::AddNumber(int number)
{
	numbers.push_back(number);
}

void OddEvenSeparator::Even()
{
	if (numbers.empty())
	{
		std::cout << "List even numbers is empty";
		return;
	}

	std::cout << "List even numbers: ";
	for (int num : numbers) 
	{
		if (num % 2 == 0) 
		{
			std::cout << num << " ";
		}
	}
	std::cout << std::endl;
}

void OddEvenSeparator::Odd()
{
	if (numbers.empty())
	{
		std::cout << "List odd numbers is empty";
		return;
	}

	std::cout << "List odd numbers: ";
	for (int num : numbers)
	{
		if (num % 2 != 0)
		{
			std::cout << num << " ";
		}
	}
	std::cout << std::endl;
}