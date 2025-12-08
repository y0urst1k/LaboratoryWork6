#pragma once
#include <string>
#include "Data.h"


std::string CarMarkToString(CarMark mark);
std::string CountryToString(Country country, bool toDisplay = true);
std::string CarColorToString(CarColor color, bool toDisplay = true);
std::string CarBodyworkToString(CarBodywork body, bool toDisplay = true);