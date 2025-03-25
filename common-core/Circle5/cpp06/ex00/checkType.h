#ifndef CHECKTYPE_H
#define CHECKTYPE_H

#include <cstdlib>
#include <iostream>
#include <limits>

typedef enum
{
    INVALID,
    SPECIAL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} e_type;

bool   isSpecial(std::string& literal);
bool   isFloat(std::string& literal);
bool   isDouble(std::string& literal);
bool   isChar(std::string& literal);
bool   isInt(std::string& literal);
e_type literalType(std::string& literal);

#endif
