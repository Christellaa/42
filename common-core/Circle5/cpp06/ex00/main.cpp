#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>

int checkOverflow(double d)
{
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        return 0;
    return 1;
}

int checkPrintable(double d)
{
    if (d < 0 || d > 127)
        return 0;
    else if (d < 32 || d > 126)
        return 1;
    return 2;
}

void convertSpecial(double d)
{
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    if (std::isnan(d))
    {
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
    }
    else
    {
        std::cout << "float : " << (d < 0 ? "-inf" : "inf") << "f" << std::endl;
        std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
    }
}

void convertNormal(double d)
{
    if (!checkOverflow(d) || !checkPrintable(d))
        std::cout << "char: impossible" << std::endl;
    else if (checkPrintable(d) == 1)
        std::cout << "char: not displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(d) << std::endl;
    if (!checkOverflow(d))
        std::cout << "int: impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << (d == static_cast<int>(d) ? ".0f" : "f")
              << std::endl;
    std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
}

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " <value>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}
