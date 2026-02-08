#pragma once

#include <string>

enum VirusType { FileBased, Bootable, MacroVirus, NetworkWorm };

enum Platform { Windows, Linux, Android, iOS };

struct Virus
{
private:
	std::string Name;
	VirusType Type;
	Platform TargetPlatform;
	double PropagationRate;
	int DayDiscovery;
	int MonthDiscovery;
	int YearDiscovery;

public:
	Virus();

	Virus(std::string Name, VirusType Type,
		Platform TargetPlatform,
		double PropagationRate,
		int DayDiscovery,
		int MonthDiscovery,
		int YearDiscovery);

	std::string GetName() const;
	VirusType GetType() const;
	Platform GetTargetPlatform() const;
	double GetPropagationRate() const;
	int GetDayDiscovery() const;
	int GetMonthDiscovery() const;
	int GetYearDiscovery() const;
	std::string GetDateDiscovery() const;

private:
	bool IsValidDate(int day, int month, int year) const;
};