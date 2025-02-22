#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bitNumber = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = roundf(number * (1 << this->_bitNumber));
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(number * (1 << this->_bitNumber));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat() const
{
    return (float) this->_value / (1 << this->_bitNumber);
}

int Fixed::toInt() const
{
    return this->_value / (1 << this->_bitNumber);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
