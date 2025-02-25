#ifndef _MATERIASOURCE_HPP_
#define _MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
class AMateria;

class MateriaSource : public IMateriaSource
{
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& copy);

    ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& rhs);

    void      learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const& type);

  private:
    AMateria* _inventory[4];
};

#endif
