#include "Point.hpp"

int main()
{
    {
        Point a(5, 5);
        Point b(2, 9);
        Point c(0, 5);
        Point p(3, 7);
        Point p2(3.5, 7);
        Point p3(4, 7);

        std::cout << "Point a.x = " << a.getX() << " a.y = " << a.getY() << std::endl;
        std::cout << "Point b.x = " << b.getX() << " b.y = " << b.getY() << std::endl;
        std::cout << "Point c.x = " << c.getX() << " c.y = " << c.getY() << std::endl;
        std::cout << "Point p.x = " << p.getX() << " p.y = " << p.getY() << std::endl;
        std::cout << "Point p2.x = " << p2.getX() << " p2.y = " << p2.getY() << std::endl;
        std::cout << "Point p3.x = " << p3.getX() << " p3.y = " << p3.getY() << std::endl;
        if (bsp(a, b, c, p))
            std::cout << "p is in the triangle" << std::endl;
        else
            std::cout << "p is outside the triangle" << std::endl;
        if (bsp(a, b, c, p2))
            std::cout << "p2 is in the triangle" << std::endl;
        else
            std::cout << "p2 is outside the triangle" << std::endl;
        if (bsp(a, b, c, p3))
            std::cout << "p3 is in the triangle" << std::endl;
        else
            std::cout << "p3 is outside the triangle" << std::endl;
    }
    std::cout << "\n" << std::endl;
    {
        Point a(-1.5, -1.5);
        Point b(2.5, 2.5);
        Point c(-1, -2);
        Point p(-1, -2);
        Point p2(-1, -1.99);
        std::cout << "Point a.x = " << a.getX() << " a.y = " << a.getY() << std::endl;
        std::cout << "Point b.x = " << b.getX() << " b.y = " << b.getY() << std::endl;
        std::cout << "Point c.x = " << c.getX() << " c.y = " << c.getY() << std::endl;
        std::cout << "Point p.x = " << p.getX() << " p.y = " << p.getY() << std::endl;
        std::cout << "Point p2.x = " << p2.getX() << " p2.y = " << p2.getY() << std::endl;
        if (bsp(a, b, c, p))
            std::cout << "p is in the triangle" << std::endl;
        else
            std::cout << "p is outside the triangle" << std::endl;
        if (bsp(a, b, c, p2))
            std::cout << "p2 is in the triangle" << std::endl;
        else
            std::cout << "p2 is outside the triangle" << std::endl;
    }
}
