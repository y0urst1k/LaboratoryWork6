#include "Data.h"
#include <ctime>

using std::string;
using std::map;

Car::Car(CarMark carmarkP,
	CarColor carColorP,
	string factorynumberP,
	int year, int month, int day,
	CarBodywork carBodyworkP,
	string nameP,
	string surnameP,
	string patronymicP)
{
	tm timeInfoRelease = {};
	timeInfoRelease.tm_year = year - 1900;
	timeInfoRelease.tm_mon = month;
	timeInfoRelease.tm_mday = day;
	releaseDate = mktime(&timeInfoRelease);
	technicalInspectionDate = time(0);

	carmark = carmarkP;
	carColor = carColorP;
	factorynumber = factorynumberP;
	carBodywork = carBodyworkP;
	name = nameP;
	surname = surnameP;
	patronymic = patronymicP;
}
Car::Car(){}