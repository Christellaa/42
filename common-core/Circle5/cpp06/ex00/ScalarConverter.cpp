#include "ScalarConverter.hpp"

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
    e_type type                        = literalType(literal);
    void (*toConvert[6])(std::string&) = {invalidLiteral, convertSpecial, convertChar,
                                          convertInt,     convertFloat,   convertDouble};
    toConvert[type](literal);
}
