#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& copy)
{
    this->_type = copy._type;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

// void AMateria::use(ICharacter& target)
// {
//     // to implement
// }
