#ifndef _IMATERIASOURCE_HPP_
#define _IMATERIASOURCE_HPP_

class AMateria;
#include <iostream>

class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void      learnMateria(AMateria*)                = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
