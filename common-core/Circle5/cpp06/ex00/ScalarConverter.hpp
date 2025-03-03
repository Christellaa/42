#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include <iostream>

class ScalarConverter
{
  public:
    static void convert(std::string literal);

  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& rhs);
};

void convertSpecial(double d);
void convertNormal(double d);

#endif
