#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(NULL)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->_type = copy._type;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "The sound of an animal" << std::endl;
}

std::string const& Animal::getType() const
{
    return this->_type;
}
