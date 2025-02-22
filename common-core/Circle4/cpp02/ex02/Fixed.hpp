#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed
{
  public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed& copy);

    ~Fixed();

    Fixed& operator=(const Fixed& rhs);

    bool operator==(const Fixed& rhs);
    bool operator!=(const Fixed& rhs);
    bool operator<(const Fixed& rhs);
    bool operator<=(const Fixed& rhs);
    bool operator>(const Fixed& rhs);
    bool operator>=(const Fixed& rhs);

    Fixed operator+(const Fixed& rhs);
    Fixed operator-(const Fixed& rhs);
    Fixed operator*(const Fixed& rhs);
    Fixed operator/(const Fixed& rhs);

    Fixed& operator++();
    Fixed  operator++(int);
    Fixed& operator--();
    Fixed  operator--(int);

    static Fixed&       min(Fixed& lhs, Fixed& rhs);
    static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
    static Fixed&       max(Fixed& lhs, Fixed& rhs);
    static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

    int  getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;

  private:
    int              _value;
    static const int _bitNumber;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
