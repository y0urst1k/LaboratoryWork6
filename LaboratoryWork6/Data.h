#ifndef DATA_H
#define DATA_H

#include <string>
#include <map>
#include <ctime>

enum class CarMark 
{
    MercedesBenz, BMW, Audi, Volkswagen, Porsche, Opel,
    Toyota, Mitsubishi, Mazda, Lexus, Nissan, Suzuki,
    Cadillac, Dodge, Chevrolet,
    Lada, ”¿«, Aurus
};

enum class Country 
{
    Germany, Japan, USA, Russia
};

enum class CarColor {
    Blue, Red, Pink, Purple, Green, Yellow
};

enum class CarBodywork 
{
    Sedan, Compartment, Hatchback, Universal
};

struct Car 
{
    Car(CarMark carmarkP,
        CarColor carColorP,
        std::string factorynumberP,
        int year, int month, int day,
        CarBodywork carBodyworkP,
        std::string nameP,
        std::string surnameP,
        std::string patronymicP){ }
    CarMark carmark;
    CarColor carColor;
    std::string factorynumber;
    std::time_t releaseDate;
    CarBodywork carBodywork;
    std::time_t technicalInspectionDate;
    std::string name;
    std::string surname;
    std::string patronymic;
};

const std::map<CarMark, Country> modelToCountry = 
{
    {CarMark::MercedesBenz, Country::Germany},
    {CarMark::BMW, Country::Germany},
    {CarMark::Audi, Country::Germany},
    {CarMark::Volkswagen, Country::Germany},
    {CarMark::Porsche, Country::Germany},
    {CarMark::Opel, Country::Germany},
    {CarMark::Toyota, Country::Japan},
    {CarMark::Mitsubishi, Country::Japan},
    {CarMark::Mazda, Country::Japan},
    {CarMark::Lexus, Country::Japan},
    {CarMark::Nissan, Country::Japan},
    {CarMark::Suzuki, Country::Japan},
    {CarMark::Cadillac, Country::USA},
    {CarMark::Dodge, Country::USA},
    {CarMark::Chevrolet, Country::USA},
    {CarMark::Lada, Country::Russia},
    {CarMark::”¿«, Country::Russia},
    {CarMark::Aurus, Country::Russia}
};

#endif