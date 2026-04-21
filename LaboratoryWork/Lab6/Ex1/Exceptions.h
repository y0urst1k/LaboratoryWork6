#pragma once

#include <iostream>
#include <string>
#include <exception>

class PasswordError : public std::exception 
{
public:
    const char* what() const noexcept override 
    {
        return "Ошибка пароля";
    }
};

class LengthError : public PasswordError 
{
public:
    const char* what() const noexcept override 
    {
        return "Пароль должен быть не менее 9 символов.";
    }
};

class RegisterError : public PasswordError 
{
public:
    const char* what() const noexcept override 
    {
        return "Пароль должен содержать символы разных регистров.";
    }
};

class DigitError : public PasswordError 
{
public:
    const char* what() const noexcept override 
    {
        return "Пароль должен содержать хотя бы одну цифру.";
    }
};

class ForbiddenLetterError : public PasswordError 
{
public:
    const char* what() const noexcept override 
    {
        return "Пароль не должен содержать символы: l, I, 1, o, O, 0.";
    }
};