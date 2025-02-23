#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type  = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type  = copy._type;
    this->_brain = new Brain(*copy._brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
        delete (this->_brain);
        this->_brain = new Brain(*rhs._brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "woof" << std::endl;
}

Brain& Dog::getBrain() const
{
    return *this->_brain;
}
