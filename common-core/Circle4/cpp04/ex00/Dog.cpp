#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = copy._type;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "woof" << std::endl;
}
