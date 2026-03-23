#pragma once
#include "../Exercise/Stock.h"

class StockManager
{
private:
	void PrintMenu();
	void ClearInputBuffer();
	void AddBox(Stock& stock);
	void GetByWeight(Stock& stock);
	void GetByVolume(Stock& stock);

public:
	void Run();
};