#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include "checkType.h"
#include "converts.h"

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

#endif
