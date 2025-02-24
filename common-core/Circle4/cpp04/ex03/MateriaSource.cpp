#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    for (int i = 0; i < 4; ++i)
        delete this->_inventory[i];
    for (int i = 0; i < 4; ++i)
    {
        if (copy._inventory[i] != NULL)
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "Destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i])
        {
            std::cout << "Deleting materia " << this->_inventory[i]->getType() << std::endl;
            delete this->_inventory[i];
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; ++i)
            delete this->_inventory[i];
        for (int i = 0; i < 4; ++i)
        {
            if (rhs._inventory[i] != NULL)
                this->_inventory[i] = rhs._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
    {
        std::cout << "Materia does not exist" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!this->_inventory[i])
        {
            std::cout << "Add materia " << materia->getType() << std::endl;
            this->_inventory[i] = materia->clone();
            delete materia;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] && this->_inventory[i]->getType() == type)
        {
            return this->_inventory[i]->clone();
        }
    }
    std::cout << "Invalid type given. Cannot create new materia" << std::endl;
    return 0;
}
