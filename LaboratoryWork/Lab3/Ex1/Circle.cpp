#include <sstream>

#include "Circle.h"

std::string Circle::to_string() 
{
    std::stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"circle\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}