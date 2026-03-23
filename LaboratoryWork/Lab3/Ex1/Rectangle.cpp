#include "Rectangle.h"
#include <sstream>

std::string Rectangle::to_string() 
{
    std::stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"rectangle\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}