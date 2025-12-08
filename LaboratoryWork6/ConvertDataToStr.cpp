#include <string>
#include "Data.h"
#include "ConvertDataToStr.h"

using std::string;

string CarMarkToString(CarMark mark) 
{
    switch (mark) 
    {
        case CarMark::MercedesBenz: 
            return "Mercedes-Benz";
        case CarMark::BMW: 
            return "BMW";
        case CarMark::Audi: 
            return "Audi";
        case CarMark::Volkswagen: 
            return "Volkswagen";
        case CarMark::Porsche: 
            return "Porsche";
        case CarMark::Opel: 
            return "Opel";
        case CarMark::Toyota: 
            return "Toyota";
        case CarMark::Mitsubishi: 
            return "Mitsubishi";
        case CarMark::Mazda: 
            return "Mazda";
        case CarMark::Lexus: 
            return "Lexus";
        case CarMark::Nissan:
            return "Nissan";
        case CarMark::Suzuki: 
            return "Suzuki";
        case CarMark::Cadillac: 
            return "Cadillac";
        case CarMark::Dodge: 
            return "Dodge";
        case CarMark::Chevrolet: 
            return "Chevrolet";
        case CarMark::Lada: 
            return "Lada";
        case CarMark::УАЗ: 
            return "УАЗ";
        case CarMark::Aurus: 
            return "Aurus";
        default: 
            return "Unknown";
    }
}

string CountryToString(Country country) 
{
    switch (country) 
    {
        case Country::Germany: 
            return "Германия";
        case Country::Japan:
            return "Япония";
        case Country::USA: 
            return "США";
        case Country::Russia: 
            return "Россия";
        default: 
            return "Unknown";
    }
}

string CarColorToString(CarColor color) 
{
    switch (color) 
    {
        case CarColor::Blue: 
            return "Синий";
        case CarColor::Red: 
            return "Красный";
        case CarColor::Pink: 
            return "Розовый";
        case CarColor::Purple: 
            return "Фмолетовый";
        case CarColor::Green: 
            return "Зеленый";
        case CarColor::Yellow: 
            return "Желтый";
        default: 
            return "Unknown";
    }
}

string CarBodyworkToString(CarBodywork body)
{
    switch (body) 
    {
        case CarBodywork::Sedan:
            return "Седан";
        case CarBodywork::Compartment: 
            return "Купе";
        case CarBodywork::Hatchback: 
            return "Хэтчбек";
        case CarBodywork::Universal: 
            return "Универсал";
        default: return 
            "Unknown";
    }
}