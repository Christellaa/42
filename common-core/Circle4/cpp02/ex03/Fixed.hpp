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

    Fixed& operator=(const Fixed& fixed);

    bool operator==(const Fixed& fixed);
    bool operator!=(const Fixed& fixed);
    bool operator<(const Fixed& fixed);
    bool operator<=(const Fixed& fixed);
    bool operator>(const Fixed& fixed);
    bool operator>=(const Fixed& fixed);

    Fixed operator+(const Fixed& fixed);
    Fixed operator-(const Fixed& fixed);
    Fixed operator*(const Fixed& fixed);
    Fixed operator/(const Fixed& fixed);

    Fixed& operator++();
    Fixed  operator++(int);
    Fixed& operator--();
    Fixed  operator--(int);

    static Fixed&       min(Fixed& fixed1, Fixed& fixed2);
    static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
    static Fixed&       max(Fixed& fixed1, Fixed& fixed2);
    static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

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
