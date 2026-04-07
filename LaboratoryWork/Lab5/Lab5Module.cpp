#include "Lab5Module.h"
#include "Ex1/Contains.h"
#include "Ex3/Matrix.h"
#include <string>
#include <iostream>
#include "../Lab4/Ex2/Rational.h"
#include "Ex4/Polynomial.h"

void Lab5Module::StartEx1()
{
    // Тест 1: массив целых чисел
    int intArray[] = { 1, 5, 8, 12, 15 };
    int intSize = 5;

    std::cout << "Тест с целыми числами:\n";
    std::cout << "Массив: ";
    for (int i = 0; i < intSize; ++i) 
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << "contains(8, intArray, intSize): "
        << (contains(8, intArray, intSize) ? "true" : "false") << "\n";
    std::cout << "contains(7, intArray, intSize): "
        << (contains(7, intArray, intSize) ? "true" : "false") << "\n\n";

    // Тест 2: массив вещественных чисел
    double doubleArray[] = { 1.5, 3.7, 8.2, 9.1, 10.5 };
    int doubleSize = 5;

    std::cout << "Тест с вещественными числами:\n";
    std::cout << "Массив: ";
    for (int i = 0; i < doubleSize; ++i) 
    {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << "contains(3.7, doubleArray, doubleSize): "
        << (contains(3.7, doubleArray, doubleSize) ? "true" : "false") << "\n";
    std::cout << "contains(5.5, doubleArray, doubleSize): "
        << (contains(5.5, doubleArray, doubleSize) ? "true" : "false") << "\n\n";

    // Тест 3: массив строк
    std::string stringArray[] = { "apple", "banana", "cherry", "date", "elderberry" };
    int stringSize = 5;

    std::cout << "Тест со строками:\n";
    std::cout << "Массив: ";
    for (int i = 0; i < stringSize; ++i)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << "contains(\"banana\", stringArray, stringSize): "
        << (contains(std::string("banana"), stringArray, stringSize) ? "true" : "false") << "\n";
    std::cout << "contains(\"grape\", stringArray, stringSize): "
        << (contains(std::string("grape"), stringArray, stringSize) ? "true" : "false") << "\n";
}

template<typename T>
void Lab5Module::printArray(T* arr, int size, const std::string& name)
{
    std::cout << name << ": ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void Lab5Module::StartEx2()
{
    // Тест 1: массив целых чисел
    int intArray[] = { 1, 5, 8, 12, 15 };
    int intSize = 5;

    std::cout << "=== Тест с целыми числами ===\n";
    printArray(intArray, intSize, "Исходный массив");

    change(5, 12, intArray, intSize);
    printArray(intArray, intSize, "После обмена 5 и 12");

    change(3, 8, intArray, intSize); // Элемент 3 отсутствует
    printArray(intArray, intSize, "После попытки обмена 3 и 8");
    std::cout << "\n";

    // Тест 2: массив вещественных чисел
    double doubleArray[] = { 1.5, 3.7, 8.2, 9.1, 10.5 };
    int doubleSize = 5;

    std::cout << "=== Тест с вещественными числами ===\n";
    printArray(doubleArray, doubleSize, "Исходный массив");

    change(3.7, 9.1, doubleArray, doubleSize);
    printArray(doubleArray, doubleSize, "После обмена 3.7 и 9.1");

    change(2.5, 8.2, doubleArray, doubleSize); // Элемент 2.5 отсутствует
    printArray(doubleArray, doubleSize, "После попытки обмена 2.5 и 8.2");
    std::cout << "\n";

    // Тест 3: массив строк
    std::string stringArray[] = { "apple", "banana", "cherry", "date", "elderberry" };
    int stringSize = 5;

    std::cout << "=== Тест со строками ===\n";
    printArray(stringArray, stringSize, "Исходный массив");

    change(std::string("banana"), std::string("date"), stringArray, stringSize);
    printArray(stringArray, stringSize, "После обмена 'banana' и 'date'");

    change(std::string("grape"), std::string("cherry"), stringArray, stringSize); // 'grape' отсутствует
    printArray(stringArray, stringSize, "После попытки обмена 'grape' и 'cherry'");
}

void Lab5Module::StartEx3() 
{
    std::cout << "=== Демонстрация работы шаблонного класса Matrix (без исключений) ===\n\n";

    // Тест 1: Матрица целых чисел
    std::cout << "--- Тест с матрицей целых чисел ---\n";
    Matrix<int> mat1(2, 3);
    mat1.Set(0, 0, 1); mat1.Set(0, 1, 2); mat1.Set(0, 2, 3);
    mat1.Set(1, 0, 4); mat1.Set(1, 1, 5); mat1.Set(1, 2, 6);
    std::cout << "Матрица 1:\n" << mat1;

    Matrix<int> mat2(2, 3);
    mat2.Set(0, 0, 7); mat2.Set(0, 1, 8); mat2.Set(0, 2, 9);
    mat2.Set(1, 0, 10); mat2.Set(1, 1, 11); mat2.Set(1, 2, 12);
    std::cout << "Матрица 2:\n" << mat2;

    // Сложение матриц
    Matrix<int> sum = mat1 + mat2;
    std::cout << "Сумма матриц:\n" << sum;

    // Умножение матриц (создаём подходящую матрицу 3x2)
    Matrix<int> mat3(3, 2);
    mat3.Set(0, 0, 1); mat3.Set(0, 1, 2);
    mat3.Set(1, 0, 3); mat3.Set(1, 1, 4);
    mat3.Set(2, 0, 5); mat3.Set(2, 1, 6);

    Matrix<int> product = mat1 * mat3;
    std::cout << "Произведение mat1 * mat3:\n" << product;

    // Попытка некорректного умножения
    Matrix<int> wrongMat(4, 5);
    Matrix<int> wrongProduct = mat1 * wrongMat;
    std::cout << "Попытка умножения mat1 на матрицу неподходящего размера:\n" << wrongProduct;

    std::cout << "\n";

    // Тест 2: Матрица строк
    std::cout << "--- Тест с матрицей строк ---\n";
    Matrix<std::string> strMat1(2, 2);
    strMat1.Set(0, 0, "Hello"); strMat1.Set(0, 1, "World");
    strMat1.Set(1, 0, "C++"); strMat1.Set(1, 1, "Matrix");
    std::cout << "Строковая матрица 1:\n" << strMat1;

    Matrix<std::string> strMat2(2, 2);
    strMat2.Set(0, 0, "Good"); strMat2.Set(0, 1, "Morning");
    strMat2.Set(1, 0, "Beautiful"); strMat2.Set(1, 1, "Day");
    std::cout << "Строковая матрица 2:\n" << strMat2;

    // Сложение строковых матриц (конкатенация строк)
    Matrix<std::string> strSum = strMat1 + strMat2;
    std::cout << "Сложение строковых матриц (конкатенация):\n" << strSum;

    // Проверка методов Set и Get
    std::cout << "\n--- Проверка методов Set и Get ---\n";
    int value;
    if (mat1.Get(1, 1, value)) {
        std::cout << "Элемент [1][1] матрицы 1: " << value << "\n";
    }

    // Ошибка при обращении к несуществующему элементу
    if (!mat1.Get(5, 5, value)) 
    {
        std::cout << "Не удалось получить элемент [5][5] — индексы вне границ\n";
    }

    // Конструктор копирования
    std::cout << "\n--- Конструктор копирования ---\n";
    Matrix<int> copiedMat = mat1;
    std::cout << "Скопированная матрица:\n" << copiedMat;

    // Поточный ввод
    std::cout << "\n--- Поточный ввод ---\n";
    std::cout << "Введите 2 строки по 3 целых числа для новой матрицы:\n";
    Matrix<int> inputMat(2, 3);
    std::cin >> inputMat;
    std::cout << "Введённая матрица:\n" << inputMat;
}

void Lab5Module::StartEx4()
{
    std::cout << "=== Демонстрация работы шаблонного класса Polynomial ===\n\n";

    // Тест 1: Многочлены с целочисленными коэффициентами
    std::cout << "--- Тест с целочисленными коэффициентами ---\n";

    // Создаём многочлен 2x^2 + 3x + 1
    std::vector<int> coeffs1 = { 1, 3, 2 }; // коэффициенты по возрастанию степени
    Polynomial<int> p1(coeffs1);
    std::cout << "Многочлен p1 (2x^2 + 3x + 1): " << p1 << "\n";

    // Создаём многочлен x + 5
    std::vector<int> coeffs2 = { 5, 1 };
    Polynomial<int> p2(coeffs2);
    std::cout << "Многочлен p2 (x + 5): " << p2 << "\n";

    // Сложение многочленов
    Polynomial<int> sum = p1 + p2;
    std::cout << "p1 + p2: " << sum << " (ожидается: 2x^2 + 4x + 6)\n";

    // Умножение многочленов
    Polynomial<int> product = p1 * p2;
    std::cout << "p1 * p2: " << product
        << " (ожидается: 2x^3 + 13x^2 + 16x + 5)\n";

    // Операции со скаляром
    Polynomial<int> scalarAdd = p1 + 10;
    std::cout << "p1 + 10: " << scalarAdd << " (ожидается: 2x^2 + 3x + 11)\n";

    // Вычисление значения в точке
    int valueAt2 = p1(2); // p1(2) = 2*(2^2) + 3*2 + 1 = 8 + 6 + 1 = 15
    std::cout << "p1(2) = " << valueAt2 << "\n";

    // Степень многочлена
    std::cout << "Степень p1: " << p1.Degree() << " (ожидается: 2)\n";

    // Доступ к коэффициентам
    std::cout << "Коэффициент при x^1 в p1: " << p1[1] << " (ожидается: 3)\n";
    std::cout << "Коэффициент при x^5 в p1: " << p1[5] << " (ожидается: 0)\n";

    std::cout << "\n--- Тест с рациональными коэффициентами ---\n";

    // Многочлен с рациональными коэффициентами: (1/2)x^2 + (1/3)x + (1/4)
    std::vector<Rational> rCoeffs1 = { Rational(1,4), Rational(1,3), Rational(1,2) };
    Polynomial<Rational> rp1(rCoeffs1);
    std::cout << "Многочлен rp1 ((1/2)x^2 + (1/3)x + (1/4)): " << rp1 << "\n";

    // Другой многочлен: (2/3)x + (3/4)
    std::vector<Rational> rCoeffs2 = { Rational(3,4), Rational(2,3) };
    Polynomial<Rational> rp2(rCoeffs2);
    std::cout << "Многочлен rp2 ((2/3)x + (3/4)): " << rp2 << "\n";

    // Сложение рациональных многочленов
    Polynomial<Rational> rSum = rp1 + rp2;
    std::cout << "rp1 + rp2: " << rSum << "\n";

    // Умножение рациональных многочленов
    Polynomial<Rational> rProduct = rp1 * rp2;
    std::cout << "rp1 * rp2: " << rProduct << "\n";

    // Вычисление значения рационального многочлена в точке
    Rational rValue = rp1(Rational(1)); // rp1(1) = (1/2)*1^2 + (1/3)*1 + (1/4) = 1/2 + 1/3 + 1/4
    std::cout << "rp1(1) = " << rValue << " (ожидается: 13/12)\n";

    // Сравнение с скаляром
    Polynomial<Rational> scalarPoly(Rational(5)); // многочлен нулевой степени со значением 5
    if (scalarPoly == Rational(5))
    {
        std::cout << "Многочлен степени 0 со значением 5 равен скаляру 5\n";
    }
}

void Lab5Module::StartLab()
{
    std::cout << "Start ex1:\n";
    StartEx1();
    std::cout << "End ex1\n";

    std::cout << "Start ex2:\n";
    StartEx2();
    std::cout << "End ex2\n";

    std::cout << "Start ex3:\n";
    StartEx3();
    std::cout << "End ex3\n";

    std::cout << "Start ex4:\n";
    StartEx4();
    std::cout << "End ex4\n";
}