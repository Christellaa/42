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
    *this = copy;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& original)
{
    if (this != &original)
        this->_value = original.getRawBits();
    return *this;
}

bool Fixed::operator==(const Fixed& fixed)
{
    return this->_value == fixed._value;
}

bool Fixed::operator!=(const Fixed& fixed)
{
    return !(this->_value == fixed._value);
}

bool Fixed::operator<(const Fixed& fixed)
{
    return (this->_value < fixed._value);
}

bool Fixed::operator<=(const Fixed& fixed)
{
    return (this->_value <= fixed._value);
}

bool Fixed::operator>(const Fixed& fixed)
{
    return (this->_value > fixed._value);
}

bool Fixed::operator>=(const Fixed& fixed)
{
    return (this->_value >= fixed._value);
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    Fixed result;
    result = this->toFloat() + fixed.toFloat();
    return result;
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    Fixed result;
    result = this->toFloat() - fixed.toFloat();
    return result;
}

Fixed Fixed::operator*(const Fixed& fixed)
{
    Fixed result;
    result = this->toFloat() * fixed.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    Fixed result;
    result = this->toFloat() / fixed.toFloat();
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

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1._value < fixed2._value)
        return fixed1;
    else
        return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1._value < fixed2._value)
        return fixed1;
    else
        return fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1._value > fixed2._value)
        return fixed1;
    else
        return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1._value > fixed2._value)
        return fixed1;
    else
        return fixed2;
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
