#include "Point.hpp"

// the calcul: (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax)
Fixed crossProduct(Point first, Point second, Point const p)
{
    Fixed result = (second.getX().toFloat() - first.getX().toFloat()) *
                       (p.getY().toFloat() - first.getY().toFloat()) -
                   (second.getY().toFloat() - first.getY().toFloat()) *
                       (p.getX().toFloat() - first.getX().toFloat());
    return result;
}
// x = largeur, y = hauteur
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed edgeAB = crossProduct(a, b, point);
    Fixed edgeBC = crossProduct(b, c, point);
    Fixed edgeCA = crossProduct(c, a, point);
    // std::cout << "AB: " << edgeAB << ", BC: " << edgeBC
    //           << ", CA: " << edgeCA << std::endl;
    if ((edgeAB > 0 && edgeBC > 0 && edgeCA > 0) || (edgeAB < 0 && edgeBC < 0 && edgeCA < 0))
        return true;
    return false;
}
