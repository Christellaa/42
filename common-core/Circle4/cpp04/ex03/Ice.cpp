#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria()
{
    std::cout << "Ice constructor called" << std::endl;
    this->_type = "ice";
}
// shouldn't be used, use clone instead
Ice::Ice(const Ice& copy) : AMateria()
{
    (void)copy;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
	}

Ice& Ice::operator=(const Ice& rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

AMateria* Ice::clone() const
{
    std::cout << "Ice clone called" << std::endl;
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
