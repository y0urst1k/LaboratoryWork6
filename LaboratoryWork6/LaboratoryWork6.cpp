//Вариант 10

#include <iostream>
#include "MatrixWork.h"
#include "MatrixWithFilesWork.h"

using std::cout;
using std::endl;
using std::fstream;
using std::ios;

void PrintSeparator(int = 50, char = '#');

int main()
{
    setlocale(LC_ALL, "Ru");

    srand(time(nullptr));

    
    PrintSeparator();

    UseMatrixWithFiles();
}

void PrintSeparator(int count, char separator)
{
    for (int i = 0; i < count; i++)
    {
        cout << separator;
    }
    cout << endl;
}