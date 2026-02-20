#pragma once
#include <string>
class Table
{
private:
	int rowsCount;
	int columnsCount;
	int** table;
	std::string messages;
	bool isInit = false;

public:
	Table(int rows, int columns);
	~Table();
	void FillTable();
	int GetValue(int row, int col);
	void SetValue(int row, int col, int value);
	int RowsCount();
	int ColumnsCount();
	void Print(bool isDebug = false);
	double Average();

};