#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->_type = copy._type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "woof" << std::endl;
}
