#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type  = "Dog";
    this->_ideas = new Brain();
}

Dog::Dog(const Dog& copy) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type  = copy._type;
    this->_ideas = copy._ideas;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_ideas;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
    {
        this->_type  = rhs._type;
        this->_ideas = rhs._ideas;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "woof" << std::endl;
}
