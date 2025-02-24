#ifndef _MATERIASOURCE_HPP_
#define _MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
class AMateria;

// MateriaSource must be able to learn "templates" of Materias to
// create them when needed. Then, you will be able to generate a new Materia using just
// a string that identifies its type.
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
