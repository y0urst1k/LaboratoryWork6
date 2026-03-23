#pragma once
#include <string>


class Bell
{
private:
	std::string ding = "ding";
	std::string dong = "dong";
	bool isDingNext = true; // ‘лаг: true Ч следующий звук ding, false Ч dong

public:
	void Sound(int iterations = 5);
};