#pragma once
#include <vector>

using std::vector;

class OddEvenSeparator
{
private:
	std::vector<int> numbers;

public:
	void AddNumber(int);

	void Even();

	void Odd();
};

