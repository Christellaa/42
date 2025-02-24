#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const AMateria& copy) {}

MateriaSource::~MateriaSource() {}

MateriaSource& MateriaSource::operator=(const AMateria& rhs) {}

void      MateriaSource::learnMateria(AMateria*)
{
	// to implement
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	if (type == "ice")
		return new Ice(); // to implement better (a clone, not a new)
	else
	return new Cure();
	std::cout << "Invalid type given. Cannot create new materia" << std::endl;
	return NULL;
}
