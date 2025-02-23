#include "Ice.hpp"

Ice::Ice() : AMateria()
{
    this->_type = "ice";
}

Ice::Ice(const Ice& copy)
{
    this->_type = copy._type;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
              << "<TargetName>" << std::endl;
}
