#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;
using std::numeric_limits;
using std::ios_base;

bool IsValidValue(int, int);
void WriteInFile(int, bool = true, bool = false);
void ReadAllFromFile();
void ReadFromFile(int);
void SearchSummEvenNumbers(bool = false);
void SearchMinPositiveNumber(bool = false);


int main()
{
    setlocale(LC_ALL, "Ru");
    int n, m;

    do
    {
        cout << "Сколько чисел записать? ";
        cin >> n;
        cout << "Сколько чисел считать? ";
        cin >> m;
    } while (!IsValidValue(n,m));

    
    WriteInFile(n);
    cout << "Набор данных: ";
    ReadFromFile(m);
    WriteInFile(n, false);
    cout << "Другой набор данных(по-честному): "; 
    ReadAllFromFile();
    SearchSummEvenNumbers();
    SearchMinPositiveNumber();
    WriteInFile(n, false, true);
    SearchSummEvenNumbers(true);
    SearchMinPositiveNumber(true);
}

bool IsValidValue(int n, int m)
{
    if (n < 1 || m < 1 || m > n)
    {
        cout << "Not a valid number!" << endl;
        return false;
    }
    return true;
}

void WriteInFile(int n, bool isFirstEx, bool useBinary)
{
    const char* filename = useBinary ? "file.bin" : "file.txt";
    ios_base::openmode mode = ios::out | ios::trunc;
    if (useBinary) 
        mode = mode | ios::binary;

    fstream fs(filename, mode);
    if (!fs.is_open())
    {
        cout << "No file found (write)" << endl;
        return;
    }

    if (!useBinary)
    {
        if (isFirstEx)
        {
            for (int i = 2; i <= n * 2; i += 2)
                fs << i << ' ';
        }
        else
        {
            int size = rand() % 3 + 1;
            for (int i = 0; i < n * size; ++i)
                fs << i << ' ';
        }
    }
    else
    {
        if (isFirstEx)
        {
            for (int i = 2; i <= n * 2; i += 2)
                fs.write((char*)&i, sizeof(i));
        }
        else
        {
            int size = std::rand() % 3 + 1;
            for (int i = 0; i < n * size; ++i)
                fs.write((char*)&i, sizeof(i));
        }
    }

    fs.close();
}

void ReadFromFile(int m)
{
    fstream fs;
    fs.open("file.txt", ios::in);

    if (!fs.is_open())
    {
        cout << "No file found (reading)" << endl;
        return;
    }

    fs.seekp(0, ios::beg);

    int number;
    for (int i = 1; i <= m; i++)
    {
        fs >> number;
        cout << number << ' ';
    }

    cout << endl;

    fs.close();
}

void ReadAllFromFile()
{
    fstream fs;
    fs.open("file.txt", ios::in);

    if (!fs.is_open())
    {
        cout << "No file found (reading)" << endl;
        return;
    }

    fs.seekp(0, ios::beg);

    int number;
    while (fs >> number)
    {
        cout << number << ' ';
    }

    cout << endl;

    fs.close();
}

void SearchSummEvenNumbers(bool isBinary)
{
    const char* filename = isBinary ? "file.bin" : "file.txt";
    ios_base::openmode mode = ios::in;
    if (isBinary)
        mode = mode | ios::binary;

    fstream fs(filename, mode);
    if (!fs.is_open())
    {
        cout << "No file found (reading)" << endl;
        return;
    }

    fs.seekp(0, ios::beg);

    int number, summ = 0;
    if (!isBinary)
    {
        while (fs >> number)
        {
            if (number % 2 == 0)
                summ += number;
        }
        cout << "Сумма четных чисел: " << summ << endl;
    }
    else
    {
        while (fs.read((char*) &number, sizeof(number)))
        {
            if (number % 2 == 0)
                summ += number;
        }
        cout << "Сумма четных чисел (из бинарного метода): " << summ << endl;
    }

    fs.close();
}

void SearchMinPositiveNumber(bool isBinary)
{
    const char* filename = isBinary ? "file.bin" : "file.txt";
    ios_base::openmode mode = ios::in;
    if (isBinary)
        mode = mode | ios::binary;

    fstream fs(filename, mode);

    if (!fs.is_open())
    {
        cout << "No file found (reading)" << endl;
        return;
    }

    fs.seekp(0, ios::beg);

    int number, min = numeric_limits<int>::max();

    if (!isBinary)
    {
        while (fs >> number)
        {
            if (number > 0 && number < min)
                min = number;
        }
        cout << "Минимальное положительное число: " << min << endl;
    }
    else
    {
        while (fs.read((char*)&number, sizeof(number)))
        {
            if (number > 0 && number < min)
                min = number;
        }
        cout << "Минимальное положительное число (из бинарного метода): " << min << endl;
    }

    fs.close();;
}

