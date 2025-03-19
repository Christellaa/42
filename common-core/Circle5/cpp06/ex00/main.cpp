#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " <value>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}
