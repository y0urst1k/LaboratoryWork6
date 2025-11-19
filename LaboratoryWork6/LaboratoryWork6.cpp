#include <iostream>
#include <random>
#include <iomanip>

using std::cout;
using std::setw;
using std::cin;
using std::endl;
using std::random_device;
using std::uniform_real_distribution;

void Ex1();
void PrintSeparator(int = 50, char = '#');
double TriangleSquare(double*, double*);
double& MaxParamLink(double&, double&, double&);
double* MaxParamPtr(double&, double&, double&);
void SwitchMaxElement(bool uselink = true);
double** GetArray(int&, int&);
void OutputArray(double**, int&, int&);
double* GetMaxElement(double**, int&, int&);
double* GetMinElement(double**, int&, int&);
void SwapElements(double*, double*);
void UseArray();

int main()
{
    setlocale(LC_ALL, "Ru");

    Ex1();
    PrintSeparator();
    
    double side = 3, high = 5;
    cout << "Площадь треугольника = " << TriangleSquare(&side, &high) << endl;
    PrintSeparator();

    SwitchMaxElement();
    SwitchMaxElement(false);
    PrintSeparator();

    UseArray();
}

void PrintSeparator(int count, char separator)
{
    for (int i = 0; i < count; i++)
    {
        cout << separator;
    }
    cout << endl;
}

void Ex1()
{
    double m = 0;
    cout << "Значение переменной = " << m << endl;

    cout << "Присваиваем указателю переменную" << endl;
    double* ptr = &m;
    cout << "*ptr = " << *ptr << endl;

    cout << "Меняем значение переменной через указатель на 100" << endl;
    *ptr = 100;
    cout << "Значение переменной  = " << m << endl;

    cout << "Копируем значение 1 указателя во второй" << endl;
    double* ptr2 = ptr;

    cout << "Меняем значение переменной через 2 указатель на 200" << endl;
    *ptr2 = 200;
    cout << "Значение переменной = " << m << endl;

    cout << "Адреса:" << endl;
    cout << "ptr: " << ptr << endl;
    cout << "ptr2: " << ptr2 << endl;
}

double TriangleSquare(double *side, double *high)
{
    if (*side <= 0)
        cout << "Сторона должна быть больше 0";
    if (*high <= 0)
        cout << "Высота должна быть больше 0";

    return *side * *high / 2;
}

double& MaxParamLink(double& item1, double& item2, double& item3)
{
    double* items[] = { &item1, &item2, &item3 };
    double* max = items[0];

    for (int i = 1; i < 3; i++)
    {
        if (*items[i] > *max)
        {
            max = items[i];
        }
    }

    return *max;
}

double* MaxParamPtr(double& item1, double& item2, double& item3)
{
    double* items[] = { &item1, &item2, &item3 };
    double* max = items[0];

    for (int i = 1; i < 3; i++)
    {
        if (*items[i] > *max)
        {
            max = items[i];
        }
    }

    return max;
}

void SwitchMaxElement(bool useLink)
{
    double item1 = -1, item2 = 2, item3 = 0;
    if (useLink)
    {
        cout << "Используем ссылку:" << endl;
        double& linkMax = MaxParamLink(item1, item2, item3);
        cout << "Максимальный параметр = " << linkMax << endl;
        double newMax = (item1 + item2 + item3) / 3;
        linkMax = newMax;
        cout << "Замена на среднее значение: " << linkMax << endl;
        cout << "Адрес: " << &linkMax << endl;
    }
    else
    {
        cout << "Используем указатель:" << endl;
        double* linkMax = MaxParamPtr(item1, item2, item3);
        cout << "Максимальный параметр = " << *linkMax << endl;
        double newMax = (item1 + item2 + item3) / 3;
        *linkMax = newMax;
        cout << "Замена на среднее значение: " << *linkMax << endl;
        cout << "Адрес: " << linkMax << endl;
    }
}

double** GetArray(int& rows, int& columns)
{
    double item;
    random_device rd;
    uniform_real_distribution<double> dis(-5.0, 5.0);

    double** data = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[columns] {};
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            item = dis(rd);
            data[i][j] = item;
        }

    return data;
}

void OutputArray(double** data, int& rows, int& columns)
{
    cout << "Массив чисел:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << setw(10) << data[i][j];
        cout << endl;
    }
    cout << endl;
}

double* GetMaxElement(double** data, int& rows, int& columns)
{
    double* max = &data[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (data[i][j] > *max)
            {
                max = &data[i][j];
            }
        }
    }

    return max;
}

double* GetMinElement(double** data, int& rows, int& columns)
{
    double* min = &data[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (data[i][j] < *min)
            {
                min = &data[i][j];
            }
        }
    }

    return min;
}

void SwapElements(double* max, double* min)
{
    double temp = *max;
    *max = *min;
    *min = temp;
}

void UseArray()
{
    int rows = 4,columns = 5;

    double** data = GetArray(rows, columns);
    OutputArray(data, rows, columns);

    double* maxItem = GetMaxElement(data, rows, columns);
    cout << "Максимальный элемент: " << *maxItem << endl;
    double* minItem = GetMinElement(data, rows, columns);
    cout << "Минимальный элемент: " << *minItem << endl;

    cout << "Поменяем макс. и мин. элементы" << endl;
    SwapElements(maxItem, minItem);
    OutputArray(data, rows, columns);

    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
}