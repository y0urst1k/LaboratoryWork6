#include <string>
#include "Data.h"
#include "ConvertDataToStr.h"

using std::string;

string CarMarkToString(CarMark mark) 
{
    switch (mark) 
    {
        case CarMark::MercedesBenz: 
            return "MercedesBenz";
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

string CountryToString(Country country, bool toDisplay) 
{
    if (toDisplay)
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
                return "Неизвестно";
            }
    }
    else
    {
        switch (country)
        {
            case Country::Germany:
                return "Germany";
            case Country::Japan:
                return "Japan";
            case Country::USA:
                return "USA";
            case Country::Russia:
                return "Russia";
            default:
                return "Unknown";
        }
    }
}

string CarColorToString(CarColor color, bool toDisplay)
{
    if (toDisplay)
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
                return "Фиолетовый";
            case CarColor::Green:
                return "Зеленый";
            case CarColor::Yellow:
                return "Желтый";
            case CarColor::Black: 
                return "Черный";
            case CarColor::White:
                return "Белый";
            case CarColor::Gray:
                return "Серый";
            default:
                return "Неизвестно";
        }
    }
    else
    {
        switch (color)
        {
            case CarColor::Blue:
                return "Blue";
            case CarColor::Red:
            return "Red";
            case CarColor::Pink:
                return "Pink";
            case CarColor::Purple:
                return "Purple";
            case CarColor::Green:
                return "Green";
            case CarColor::Yellow:
                return "Yellow";
            case CarColor::Black: 
                return "Black";
            case CarColor::White:
                return "White"; 
            case CarColor::Gray:
                return "Gray";
            default:
                return "Unknown";
        }
    }
}

string CarBodyworkToString(CarBodywork body, bool toDisplay)
{
    if (toDisplay)
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
                "Неизвестно";
        }
    }
    else
    {
        switch (body)
        {
            case CarBodywork::Sedan:
                return "Sedan";
            case CarBodywork::Compartment:
                return "Compartment";
            case CarBodywork::Hatchback:
                return "Hatchback";
            case CarBodywork::Universal:
                return "Universal";
            default: return
                "Неизвестно";
        }
    }
}