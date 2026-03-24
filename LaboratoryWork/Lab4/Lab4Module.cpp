#include "Lab4Module.h"
#include <iostream>
#include "../Lab2/Exercise/Complex.h"
#include "Ex2/Rational.h"

using std::cout;
using std::endl;

void Lab4Module::StartEx1()
{
    // 1. Конструктор копирования
    cout << "Copy and use <<" << endl;
    Complex z1(3, 4);
    Complex z2 = z1; // копирование
    cout << "z1 = " << z1 << endl; // используем <<
    cout << "z2 = " << z2 << endl;

    // 2. Арифметические операции
    cout << "Ariphmetic operations" << endl;
    Complex z3 = z1 + z2;
    cout << "z1 + z2 = " << z3 << endl;

    Complex z4 = z1 * z2;
    cout << "z1 * z2 = " << z4 << endl;

    Complex z5 = z1 - z2;
    cout << "z1 - z2 = " << z5 << endl;

    Complex z6 = z1 / z2;
    cout << "z1 / z2 = " << z6 << endl;

    // 3. Инкремент/декремент
    cout << "inc" << endl;
    ++z1;
    cout << "++z1 = " << z1 << endl;

    cout << "dec" << endl;
    z2--;
    cout << "z2-- = " << z2 << endl;

    // 4. Логические операции
    cout << "logic operations" << endl;
    if (z1 > z2) cout << "z1 > z2" << endl;
    if (z1 != z2) cout << "z1 != z2" << endl;

    // 5. Ввод-вывод
    cout << "in/out-put" << endl;
    Complex z7;
    cout << "Введите действительную и мнимую части: ";
    std::cin >> z7; // используем >>
    cout << "Введённое число: " << z7 << endl;
}

void Lab4Module::StartEx2()
{
    // Тест 1: Создание объектов и конструктор
    std::cout << "Тест 1: Создание объектов\n";
    Rational r1;                    // 0/1 по умолчанию
    Rational r2(3, 4);        // 3/4
    Rational r3(6, 8);        // 6/8 → 3/4 (сокращение)
    Rational r4(-2, 3);       // -2/3
    Rational r5(2, -3);       // 2/-3 → -2/3 (нормализация знака)
    Rational r6(0, 5);       // 0/5 → 0/1
    Rational r7(5, 0);       // 5/0 → 0/1 (обработка нуля в знаменателе)

    std::cout << "r1 (по умолчанию): " << r1 << std::endl;
    std::cout << "r2 (3, 4): " << r2 << std::endl;
    std::cout << "r3 (6, 8): " << r3 << std::endl;
    std::cout << "r4 (-2, 3): " << r4 << std::endl;
    std::cout << "r5 (2, -3): " << r5 << std::endl;
    std::cout << "r6 (0, 5): " << r6 << std::endl;
    std::cout << "r7 (5, 0): " << r7 << std::endl;

    // Тест 2: Функции-члены Numerator и Denominator
    std::cout << "\nТест 2: Функции Numerator() и Denominator()\n";
    std::cout << "r2: числитель = " << r2.Numerator()
        << ", знаменатель = " << r2.Denominator() << std::endl;
    std::cout << "r3: числитель = " << r3.Numerator()
        << ", знаменатель = " << r3.Denominator() << std::endl;

    // Тест 3: Унарные операторы
    std::cout << "\nТест 3: Унарные операторы\n";
    std::cout << "+r2 = " << +r2 << std::endl;
    std::cout << "-r2 = " << -r2 << std::endl;
    std::cout << "-r4 = " << -r4 << std::endl;

    // Тест 4: Бинарные операторы с Rational
    std::cout << "\nТест 4: Бинарные операторы (Rational + Rational)\n";
    std::cout << r2 << " + " << r3 << " = " << (r2 + r3) << std::endl;
    std::cout << r2 << " - " << r3 << " = " << (r2 - r3) << std::endl;
    std::cout << r2 << " * " << r3 << " = " << (r2 * r3) << std::endl;
    std::cout << r2 << " / " << r3 << " = " << (r2 / r3) << std::endl;

    // Тест 5: Бинарные операторы с int
    std::cout << "\nТест 5: Бинарные операторы (с int)\n";
    std::cout << r2 << " + 2 = " << (r2 + 2) << std::endl;
    std::cout << "2 + " << r2 << " = " << (2 + r2) << std::endl;
    std::cout << r2 << " - 1 = " << (r2 - 1) << std::endl;
    std::cout << "1 - " << r2 << " = " << (1 - r2) << std::endl;
    std::cout << r2 << " * 3 = " << (r2 * 3) << std::endl;
    std::cout << "3 * " << r2 << " = " << (3 * r2) << std::endl;
    std::cout << r2 << " / 2 = " << (r2 / 2) << std::endl;
    std::cout << "2 / " << r2 << " = " << (2 / r2) << std::endl;

    // Тест 6: Составные операторы
    std::cout << "\nТест 6: Составные операторы\n";
    Rational temp = r2;
    std::cout << "temp = " << temp << std::endl;
    temp += r3;
    std::cout << "temp += " << r3 << " → " << temp << std::endl;
    temp -= 1;
    std::cout << "temp -= 1 → " << temp << std::endl;
    temp *= 2;
    std::cout << "temp *= 2 → " << temp << std::endl;
    temp /= r2;
    std::cout << "temp /= " << r2 << " → " << temp << std::endl;

    // Тест 7: Операторы сравнения
    std::cout << "\nТест 7: Операторы сравнения\n";
    std::cout << r2 << " == " << r3 << ": " << (r2 == r3 ? "true" : "false") << std::endl;
    std::cout << r2 << " != " << r3 << ": " << (r2 != r3 ? "true" : "false") << std::endl;
    std::cout << r2 << " == " << Rational(3, 4) << ": "
        << (r2 == Rational(3, 4) ? "true" : "false") << std::endl;
    std::cout << r4 << " == " << r5 << ": " << (r4 == r5 ? "true" : "false") << std::endl; // -2/3 == -2/3

    // Тест 8: Деление на ноль (проверка обработки)
    std::cout << "\nТест 8: Обработка деления на ноль\n";
    Rational zero(0, 1);
    Rational result1 = r2 / zero;
    std::cout << r2 << " / " << zero << " = " << result1 << std::endl;
    Rational result2 = 5 / zero;
    std::cout << "5 / " << zero << " = " << result2 << std::endl;
    Rational result3 = zero / r2;
    std::cout << zero << " / " << r2 << " = " << result3 << std::endl;

    // Тест 9: Сокращение дробей
    std::cout << "\nТест 9: Автоматическое сокращение дробей\n";
    Rational frac1(8, 12);  // 8/12 → 2/3
    Rational frac2(15, 25); // 15/25 → 3/5
    std::cout << "8/12 автоматически сократилось до: " << frac1 << std::endl;
    std::cout << "15/25 автоматически сократилось до: " << frac2 << std::endl;

    // Тест 10: Цепочки операций
    std::cout << "\nТест 10: Цепочки операций\n";
    Rational chain = r2 + r3 * 2 - 1 / r2;
    std::cout << "Цепочка: " << r2 << " + " << r3 << " * 2 - 1 / "
        << r2 << " = " << chain << std::endl;
}

void Lab4Module::StartLab()
{
	cout << "Start ex 1" << endl;
	StartEx1();
	cout << "Finish ex 1";
	cout << std::endl;

	cout << "Start ex 2" << endl;
	StartEx2();
	cout << "Finish ex 2";
	cout << endl;
}