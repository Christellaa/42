#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void) copy;
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void) rhs;
    return *this;
}

void ScalarConverter::convert(std::string literal)
{
    double d;
    char*  end;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        d = static_cast<double>(literal[0]);
        convertNormal(d);
        return;
    }
    if (!literal.empty() &&
        (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F'))
    {
        if (isdigit(literal[literal.length() - 2]) ||
            (literal.length() > 3 && (literal.substr(literal.length() - 4) == "nanf" ||
                                      literal.substr(literal.length() - 4) == "inff")))
            literal = literal.substr(0, literal.length() - 1);
    }
    d = std::strtod(literal.c_str(), &end);
    if (*end != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (std::isnan(d) || std::isinf(d))
        convertSpecial(d);
    else
        convertNormal(d);
}
