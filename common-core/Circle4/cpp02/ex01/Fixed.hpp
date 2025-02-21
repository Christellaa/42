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
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

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
