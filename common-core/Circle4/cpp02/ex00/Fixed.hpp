#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed
{
  public:
    Fixed();
    // copy construct
    Fixed(const Fixed& copy);
    // overloaded operator
    ~Fixed();

    Fixed& operator=(const Fixed& fixed);

    int  getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int              _value;
    static const int _bitNumber;
};

#endif
