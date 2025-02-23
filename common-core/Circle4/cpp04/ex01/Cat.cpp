#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type  = "Cat";
    this->_ideas = new Brain();
}

Cat::Cat(const Cat& copy) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type  = copy._type;
    this->_ideas = copy._ideas;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_ideas;
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs)
    {
        this->_type  = rhs._type;
        this->_ideas = rhs._ideas;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "miaou" << std::endl;
}
