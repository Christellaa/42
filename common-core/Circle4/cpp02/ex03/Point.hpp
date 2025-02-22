#ifndef _POINT_H_
#define _POINT_H_

#include "Fixed.hpp"

class Point
{
  public:
    Point();
    Point(const float x, const float y);
    Point(const Point& copy);
    Point& operator=(const Point& rhs);
    ~Point();

    const Fixed& getX() const;
    const Fixed& getY() const;

  private:
    const Fixed _x;
    const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
