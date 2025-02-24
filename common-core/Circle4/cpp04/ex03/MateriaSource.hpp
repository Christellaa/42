#ifndef _MATERIASOURCE_HPP_
#define _MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"

// MateriaSource must be able to learn "templates" of Materias to
// create them when needed. Then, you will be able to generate a new Materia using just
// a string that identifies its type.
class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource();
    MateriaSource(const AMateria& copy);

	~MateriaSource();

    MateriaSource& operator=(const AMateria& rhs);

	// Copies the Materia passed as a parameter and store it in memory so it can be cloned
	// later. Like the Character, the MateriaSource can know at most 4 Materias. They
	// are not necessarily unique.
    void      learnMateria(AMateria*);
    // Returns a new Materia. The latter is a copy of the Materia previously learned by
	// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
	// the type is unknown.
	AMateria* createMateria(std::string const& type);
};

#endif
