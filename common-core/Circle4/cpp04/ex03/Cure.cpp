#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria()
{
    this->_type = "cure";
}

Cure::Cure(const Cure& copy) : AMateria()
{
    this->_type = copy._type;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
