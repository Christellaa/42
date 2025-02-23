#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = "default idea";
}

Brain::Brain(const Brain& copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = copy._ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; ++i)
            this->_ideas[i] = rhs._ideas[i];
    }
    return *this;
}

void Brain::setIdea(int idx, std::string idea)
{
    this->_ideas[idx] = idea;
}

std::string const& Brain::getIdea(int idx) const
{
    return this->_ideas[idx];
}
