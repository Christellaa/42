#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = copy._type;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}
