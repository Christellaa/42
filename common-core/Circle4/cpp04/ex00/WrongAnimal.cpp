#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(NULL)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->_type = copy._type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Hello, I am nonsense" << std::endl;
}

std::string const& WrongAnimal::getType() const
{
    return this->_type;
}
