#pragma once

#include <string>

enum class VirusType { FileBased, Bootable, MacroVirus, NetworkWorm, Unknown };

enum class Platform{ Windows, Linux, Android, iOS, Unknown };

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
	std::string GetTypeString() const;
	std::string GetPlatformString() const;

private:
	bool IsValidDate(int day, int month, int year) const;
};