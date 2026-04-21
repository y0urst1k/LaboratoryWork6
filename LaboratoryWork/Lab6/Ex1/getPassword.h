#pragma once

#include <iostream>
#include <string>
#include "Exceptions.h"

std::string get_password() 
{
    std::string password;
    std::cout << "Введите пароль: ";
    std::getline(std::cin, password);

    // Проверка длины пароля (минимум 9 символов)
    if (password.length() < 9) 
    {
        throw LengthError();
    }

    // Проверка на наличие символов разных регистров
    bool has_upper = false, has_lower = false;
    for (char ch : password) 
    {
        if (std::isupper(ch)) has_upper = true;
        if (std::islower(ch)) has_lower = true;
    }
    if (!has_upper || !has_lower) 
    {
        throw RegisterError();
    }

    // Проверка на наличие хотя бы одной цифры
    bool has_digit = false;
    for (char ch : password) 
    {
        if (std::isdigit(ch)) has_digit = true;
    }
    if (!has_digit) 
    {
        throw DigitError();
    }

    // Проверка на наличие запрещённых символов
    const std::string forbidden_chars = "lIoO10";
    for (char ch : password) 
    {
        if (forbidden_chars.find(ch) != std::string::npos)
        {
            throw ForbiddenLetterError();
        }
    }

    return password;
}