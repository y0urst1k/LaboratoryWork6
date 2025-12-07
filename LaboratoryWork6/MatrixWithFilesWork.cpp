#include <iostream>
#include <fstream>
#include <iomanip>
#include "General.h"
#include "MatrixWithFilesWork.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::setw;
using std::string;
using std::ios;

void OutputMatrix(int**& matrix, int& rows, int& columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(4) << matrix[i][j];
        }

        cout << endl;
    }

    cout << endl;
}

void OutputVector(int*& vector, int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << vector[i];
    }

    cout << endl;
}

int**& GetMatrix(int& rows, int& columns, int& start, int& end)
{
    int*** matrix = new int**;
    *matrix = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        (*matrix)[i] = new int[columns];

        for (int j = 0; j < columns; j++)
        {
            (*matrix)[i][j] = GetFromInterval(start, end);
        }
    }

    return *matrix;
}

int*& GetVector(int& size, int& start, int& end)
{
    int** vector = new int*;
    *vector = new int[size];

    for (int i = 0; i < size; i++)
    {
        (*vector)[i] = GetFromInterval(start, end);
    }

    return *vector;
}

void WriteMatrixInFile(int**& matrix, char matrixName, int& rows, int& columns, fstream& file)
{
    file << "Matrix: " << matrixName << endl;

    file << rows << " " << columns << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }
}

void WriteVectorInFile(int*& vector, int& size, char vectorName, fstream& file)
{
    file << "Vector: " << vectorName << endl;

    file << size << endl;

    for (int i = 0; i < size; i++) 
    {
        file << vector[i] << " ";
    }
    file << endl;
}

void ReadMatrixFromFile(int**& matrix, fstream& file)
{
    string label;
    char matrixName;
    file >> label >> matrixName;

    int rows, cols;
    file >> rows >> cols;

    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            file >> matrix[i][j];
        }
    }
}

void ReadVectorFromFile(int*& vector, fstream& file)
{
    string label;
    char vectorName;
    file >> label >> vectorName;

    int size;
    file >> size;

    vector = new int[size];

    for (int i = 0; i < size; i++) 
    {
        file >> vector[i];
    }
}

void TranspositionMatrix(int**& matrix, int& rows, int& columns)
{
    int** temp = new int* [columns];
    for (int i = 0; i < columns; i++)
    {
        temp[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            temp[j][i] = matrix[i][j];
        }
    }

    ClearMatrix(matrix,rows);

    matrix = temp;

    int tempSize = rows;
    rows = columns;
    columns = tempSize;
}

int** MatrixMultiplication(int**& matrix1, int& rows1, int& columns1, int**& matrix2, int& rows2, int& columns2)
{
    if (columns1 != rows2) 
    {
        cout << "Нельзя перемножить данные матрицы: columns1 (" << columns1
            << ") != rows2 (" << rows2 << ")" << endl;
        return nullptr;
    }

    // Размеры результирующей матрицы
    int resultRows = rows1;
    int resultCols = columns2;

    int** result = new int* [resultRows];
    for (int i = 0; i < resultRows; i++) 
    {
        result[i] = new int[resultCols];
    }

    for (int i = 0; i < resultRows; i++) 
    {
        for (int j = 0; j < resultCols; j++) 
        {
            result[i][j] = 0;

            // Суммируем произведения
            for (int k = 0; k < columns1; k++) 
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int** VectorMultiplication(int*& vector1, int& size1, int*& vector2, int& size2)
{
    // Размеры результирующей матрицы
    int resultRows = size1;
    int resultCols = size2;

    int** result = new int* [size1];
    for (int i = 0; i < size1; ++i) 
    {
        result[i] = new int[size2];

        // Заполняем строку i: result[i][j] = vecA[i] * vecB[j]
        for (int j = 0; j < size2; j++) 
        {
            result[i][j] = vector1[i] * vector2[j];
        }
    }

    return result;
}

int** MultiplyMatrixByNumber(int**& matrix, int& rows, int& columns, int& number)
{
    if (matrix == nullptr)
    {
        cout << "Матрица не инициализирована!" << endl;
        return nullptr;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = matrix[i][j] * number;
        }
    }

    return matrix;
}

int** DefinitionMatrix(int**& matrix1, int& rows1, int& columns1, int**& matrix2, int& rows2, int& columns2)
{
    if (rows1 != rows2 || columns1 != columns2)
        return nullptr;

    int** result = new int*[rows1];
    for (int i = 0;i < rows1;i++)
    {
        result[i] = new int[columns1];

        for (int j = 0; j < columns1; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

void UseMatrixWithFiles()
{
    int rowsA = 3, columnsA = 4, rowsC = 3, columnsC = 4, sizeB = 3, sizeD = 3, startInterval = -5, endInterval = 5;

    int**& matrixA = GetMatrix(rowsA, columnsA, startInterval, endInterval);
    int**& matrixC = GetMatrix(rowsC, columnsC, startInterval, endInterval);
    int*& vectorB = GetVector(sizeB, startInterval, endInterval);
    int*& vectorD = GetVector(sizeD, startInterval, endInterval);

    cout << "Матрица А:" << endl;
    OutputMatrix(matrixA, rowsA, columnsA);
    cout << "Матрица С:" << endl;
    OutputMatrix(matrixC, rowsC, columnsC);

    cout << "Вектор В:" << endl;
    OutputVector(vectorB, sizeB);
    cout << "Вектор D:" << endl;
    OutputVector(vectorD, sizeD);


    fstream file;

    file.open("data.txt", ios::out | ios::trunc);

    cout << "Записываем данные в файл...:" << endl;
    WriteMatrixInFile(matrixA, 'A', rowsA, columnsA, file);
    WriteMatrixInFile(matrixC, 'C', rowsC, columnsC, file);
    WriteVectorInFile(vectorB, sizeB, 'B', file);
    WriteVectorInFile(vectorD, sizeD, 'D', file);

    file.close();

    cout << "Очищаем данные...:" << endl;
    ClearMatrix(matrixA, rowsA);
    ClearMatrix(matrixC, rowsC);
    delete[] vectorB;
    vectorB = nullptr;
    delete[] vectorD;
    vectorD = nullptr;

    file.open("data.txt", ios::in);

    cout << "Считываем данные из файла...:" << endl;
    ReadMatrixFromFile(matrixA, file);
    ReadMatrixFromFile(matrixC, file);
    ReadVectorFromFile(vectorB, file);
    ReadVectorFromFile(vectorD, file);

    file.close();

    cout << "Матрица А:" << endl;
    OutputMatrix(matrixA, rowsA, columnsA);
    cout << "Матрица С:" << endl;
    OutputMatrix(matrixC, rowsC, columnsC);

    cout << "Вектор В:" << endl;
    OutputVector(vectorB, sizeB);
    cout << "Вектор D:" << endl;
    OutputVector(vectorD, sizeD);

    cout << "Транспонируем матрицу C:" << endl;
    TranspositionMatrix(matrixC, rowsC, columnsC);
    cout << "Матрица С:" << endl;
    OutputMatrix(matrixC, rowsC, columnsC);

    int** matrixAC = MatrixMultiplication(matrixA, rowsA, columnsA, matrixC, rowsC, columnsC);
    cout << "Матрица, полученная перемножением матриц А и С:" << endl;
    OutputMatrix(matrixAC, rowsA, columnsC);

    int numberM = -1, numberV = 2;
    int** matrixAC_Number = MultiplyMatrixByNumber(matrixAC, rowsA, columnsC, numberM);
    cout << "Матрица, полученная умножением матрицы АС на -1:" << endl;
    OutputMatrix(matrixAC_Number, rowsA, columnsC);

    int** matrixBD = VectorMultiplication(vectorB, sizeB, vectorD, sizeD);
    cout << "Матрица, полученная перемножением векторов B и Dт:" << endl;
    OutputMatrix(matrixBD, sizeB, sizeD);

    int** matrixBD_Number = MultiplyMatrixByNumber(matrixBD, sizeB, sizeD, numberV);
    cout << "Матрица, полученная умножением матрицы BDт на 2:" << endl;
    OutputMatrix(matrixBD_Number, rowsA, columnsC);

    int** result = DefinitionMatrix(matrixAC_Number, rowsA, columnsC, matrixBD_Number, rowsA, columnsC);
    cout << "Итоговая матрица:" << endl;
    OutputMatrix(result, rowsA, columnsC);

    ClearMatrix(matrixAC, rowsA);
    ClearMatrix(matrixBD, rowsA);
    ClearMatrix(result, rowsA);
    delete[] vectorB;
    vectorB = nullptr;
    delete[] vectorD;
    vectorD = nullptr;
}