#include "Data.h"
#include <string>
#include <vector>
#include <fstream>

#pragma once

void PrintCar(const Car& car);
void PrintAllCars(const std::vector<Car>& cars);
void FindByMark(const std::vector<Car>& cars, CarMark mark);
void FindByOwner(const std::vector<Car>& cars, const std::string& name, const std::string& surname, const std::string& patronymic);
void Menu(std::vector<Car>& cars);
void WriteDataInFile(const std::vector<Car>& cars, std::fstream& file);
void ReadDataFromFile(std::vector<Car>& cars, std::fstream& file);
CarMark CarMarkFromString(const std::string& str);
CarColor CarColorFromString(const std::string& str);
CarBodywork CarBodyworkFromString(const std::string& str);
void InitializeCars(std::vector<Car>& cars);