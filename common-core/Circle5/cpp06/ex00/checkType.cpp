#include "checkType.h"

bool isSpecial(std::string& literal)
{
    if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "nanf" ||
        literal == "-inff" || literal == "+inff")
        return true;
    return false;
}

bool isFloat(std::string& literal)
{
    size_t dot = literal.find('.');
    size_t f   = literal.find('f');
    if (f != std::string::npos && dot != std::string::npos)
    {
        char* end    = NULL;
        float number = std::strtof(literal.substr(0, f).c_str(), &end);
        if (*end != '\0')
            return false;
        if (number == std::numeric_limits<float>::infinity() ||
            number == -std::numeric_limits<float>::infinity())
            return false;
        return true;
    }
    return false;
}

bool isDouble(std::string& literal)
{
    size_t dot = literal.find('.');
    size_t f   = literal.find('f');
    if (f == std::string::npos && dot != std::string::npos)
    {
        char*  end    = NULL;
        double number = std::strtod(literal.c_str(), &end);
        if (*end != '\0')
            return false;
        if (number == std::numeric_limits<double>::infinity() ||
            number == -std::numeric_limits<double>::infinity())
            return false;
        return true;
    }
    return false;
}

bool isChar(std::string& literal)
{
    size_t len = literal.length();
    if (len == 1 && !isdigit(literal[0]))
        return true;
    return false;
}

bool isInt(std::string& literal)
{
    char* end;
    long  number = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
        return false;
    return true;
}

e_type literalType(std::string& literal)
{
    if (isSpecial(literal))
        return SPECIAL;
    else if (isFloat(literal))
        return FLOAT;
    else if (isDouble(literal))
        return DOUBLE;
    else if (isChar(literal))
        return CHAR;
    else if (isInt(literal))
        return INT;
    return INVALID;
}
