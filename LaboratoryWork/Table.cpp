#include "Table.h"
#include <iostream>

Table::Table(int rows, int columns)
{
	if (rows < 0 || columns < 0)
	{
		rowsCount = 2;
		columnsCount = 2;
		messages = "rows or columns < 0, default init table 2x2\n";
	}

	else
	{
		rowsCount = rows;
		columnsCount = columns;
	}

	table = new int* [rowsCount];

	for (int i = 0; i < rowsCount; i++)
	{
		table[i] = new int[columnsCount];
	}

	isInit = true;

	messages.append("Table is init with: ");
	messages.append(std::to_string(rowsCount));
	messages.append(" rows & ");
	messages.append(std::to_string(columnsCount));
	messages.append(" columns\n");

	FillTable();
	messages.append("Fill table");
	messages.append("\n");
}

void Table::FillTable()
{
	if (!isInit)
	{
		for (int i = 0; i < rowsCount; i++)
			for (int j = 0; j < columnsCount; j++)
				table[i][j] = 0;
	}
	else
	{
		for (int i = 0; i < rowsCount; i++)
			for (int j = 0; j < columnsCount; j++)
				table[i][j] = rand() % 100;
		messages.append("Fill table witn numbers");
		messages.append("\n");
	}
}

Table::~Table()
{
	for (int i = 0; i < rowsCount; i++)
		delete table[i];

	delete[] table;
	table = nullptr;
}

int Table::GetValue(int row, int col) 
{
	messages.append("Get return: ");
	messages.append(std::to_string(table[row][col]));
	messages.append("\n");
	return table[row][col];
}

void Table::SetValue(int row, int col, int value)
{
	table[row][col] = value;
	messages.append("Set gift: ");
	messages.append(std::to_string(table[row][col]));
	messages.append("\n");
}

int Table::RowsCount()
{
	messages.append("RowsCount return ");
	messages.append(std::to_string(rowsCount));
	messages.append("\n");
	return rowsCount;
}

int Table::ColumnsCount()
{
	messages.append("ColumnsCount return ");
	messages.append(std::to_string(columnsCount));
	messages.append("\n");
	return columnsCount;
}

void Table::Print(bool isDebug)
{
	if (isDebug)
	{
		std::cout << messages << std::endl;
	}
	else
	{
		for (int i = 0; i < rowsCount; i++)
		{
			for (int j = 0; j < columnsCount; j++)
				std::cout << table[i][j] << " ";
			std::cout << std::endl;
		}
	}
}

double Table::Average()
{
	double s = 0;
	for (int i = 0; i < rowsCount; i++)
		for (int j = 0; j < columnsCount; j++)
			s += table[i][j];

	return s / (rowsCount * columnsCount);
}