#include "Data.h"
#include <iostream>

using std::string;
using std::cout;

Virus::Virus()
    : Name("Неизвестный"),
    Type(VirusType::FileBased),
    TargetPlatform(Platform::Windows),
    PropagationRate(0.0),
    DayDiscovery(1),
    MonthDiscovery(1),
    YearDiscovery(2000) {}

// Полный конструктор
Virus::Virus(std::string Name, 
    VirusType Type, 
    Platform TargetPlatform,
    double PropagationRate, 
    int DayDiscovery, 
    int MonthDiscovery, 
    int YearDiscovery)
    : Name(Name),
    Type(Type),
    TargetPlatform(TargetPlatform),
    PropagationRate(PropagationRate),
    DayDiscovery(DayDiscovery),
    MonthDiscovery(MonthDiscovery),
    YearDiscovery(YearDiscovery) 
{
    if (!IsValidDate(DayDiscovery, MonthDiscovery, YearDiscovery)) 
    {
        DayDiscovery = 1; MonthDiscovery = 1; YearDiscovery = 2000;
    }
}

// Свойства
std::string Virus::GetName() const { return Name; }
VirusType Virus::GetType() const { return Type; }
Platform Virus::GetTargetPlatform() const { return TargetPlatform; }
double Virus::GetPropagationRate() const { return PropagationRate; }
int Virus::GetDayDiscovery() const { return DayDiscovery; }
int Virus::GetMonthDiscovery() const { return MonthDiscovery; }
int Virus::GetYearDiscovery() const { return YearDiscovery; }

// Метод для получения даты в виде строки
std::string Virus::GetDateDiscovery() const 
{
    return std::to_string(DayDiscovery) + "." + std::to_string(MonthDiscovery) + "." + std::to_string(YearDiscovery);
}

// Метод проверки даты
bool Virus::IsValidDate(int Day, int Month, int Year) const 
{
    if (Year < 1970 || Year > 2100) 
        return false;
    if (Month < 1 || Month > 12) 
        return false;

    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (Day < 1 || Day > daysInMonth[Month - 1]) 
        return false;

    return true;
}