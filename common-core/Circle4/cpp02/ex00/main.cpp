#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    Fixed d;
    d.setRawBits(5);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << d.getRawBits() << std::endl;
}
