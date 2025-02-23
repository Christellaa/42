#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type  = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type  = copy._type;
    this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
        delete (this->_brain);
        this->_brain = new Brain(*rhs._brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}

Brain& Cat::getBrain() const
{
    return *this->_brain;
}
