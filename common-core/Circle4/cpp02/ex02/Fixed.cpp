#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bitNumber = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int number)
{
    this->_value = number * (1 << this->_bitNumber);
}

Fixed::Fixed(const float number)
{
    this->_value = roundf(number * (1 << this->_bitNumber));
}

Fixed::Fixed(const Fixed& copy)
{
    this->_value = copy.getRawBits();
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

bool Fixed::operator==(const Fixed& rhs)
{
    return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed& rhs)
{
    return !(this->_value == rhs._value);
}

bool Fixed::operator<(const Fixed& rhs)
{
    return (this->_value < rhs._value);
}

bool Fixed::operator<=(const Fixed& rhs)
{
    return (this->_value <= rhs._value);
}

bool Fixed::operator>(const Fixed& rhs)
{
    return (this->_value > rhs._value);
}

bool Fixed::operator>=(const Fixed& rhs)
{
    return (this->_value >= rhs._value);
}

Fixed Fixed::operator+(const Fixed& rhs)
{
    Fixed result;
    result = this->toFloat() + rhs.toFloat();
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs)
{
    Fixed result;
    result = this->toFloat() - rhs.toFloat();
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs)
{
    Fixed result;
    result = this->toFloat() * rhs.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs)
{
    Fixed result;
    result = this->toFloat() / rhs.toFloat();
    return result;
}

Fixed& Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed copy = *this;
    this->_value++;
    return copy;
}

Fixed& Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed copy = *this;
    this->_value--;
    return copy;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    if (lhs._value < rhs._value)
        return lhs;
    else
        return rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    if (lhs._value < rhs._value)
        return lhs;
    else
        return rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    if (lhs._value > rhs._value)
        return lhs;
    else
        return rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    if (lhs._value > rhs._value)
        return lhs;
    else
        return rhs;
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
