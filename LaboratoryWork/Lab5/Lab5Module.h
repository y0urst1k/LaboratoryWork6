#pragma once

#include <string>

class Lab5Module
{
	void StartEx1();
	void StartEx2();
	void StartEx3();
	void StartEx4();
	template<typename T>
	void printArray(T* arr, int size, const std::string& name);

public:
	void StartLab();
};