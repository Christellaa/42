#include "Character.hpp"
#include "Ice.hpp"

Character::Character() : _name("default")
{
    std::cout << "Character's " << this->_name << " constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 4; ++i)
        this->_floor[i] = NULL;
}

Character::Character(const Character& copy)
{
    this->_name = copy._name;
    deleteMaterias();
    for (int i = 0; i < 4; ++i)
    {
        if (copy._inventory[i] != NULL)
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
        if (copy._floor[i] != NULL)
            this->_floor[i] = copy._floor[i]->clone();
        else
            this->_floor[i] = NULL;
    }
}

Character::Character(const std::string& name) : _name(name)
{
    std::cout << "Character's " << this->_name << " constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 4; ++i)
        this->_floor[i] = NULL;
}

Character::~Character()
{
    std::cout << "Character's " << this->_name << " destructor called" << std::endl;
    deleteMaterias();
}

Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        deleteMaterias();
        for (int i = 0; i < 4; ++i)
        {
            if (rhs._inventory[i] != NULL)
                this->_inventory[i] = rhs._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
            if (rhs._floor[i] != NULL)
                this->_floor[i] = rhs._floor[i]->clone();
            else
                this->_floor[i] = NULL;
        }
    }
    return *this;
}

std::string const& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Materia does not exist" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] && this->_inventory[i] == m)
        {
            std::cout << "This materia is already equipped" << std::endl;
            return;
        }
        else if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            return;
        }
    }
    std::cout << this->_name << "'s inventory is full. Cannot equip more materia" << std::endl;
    for (int j = 0; j < 4; ++j)
    {
        if (!this->_floor[j])
        {
            this->_floor[j] = m;
            std::cout << this->_name << " left " << m->getType() << " on the floor" << std::endl;
            return;
        }
    }
    std::cout << this->_name <<
        "'s inventory is full and the floor is full of materias. Materia is deleted" << std::endl;
    delete m;
    return;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index. Must be between 0 and 3" << std::endl;
        return;
    }
    if (this->_inventory[idx])
    {
        for (int i = 0; i < 4; ++i)
        {
            if (!this->_floor[i])
            {
                this->_floor[i] = this->_inventory[idx];
                this->_inventory[idx]       = NULL;
                shiftLeftMaterias(idx, this->_inventory);
                return;
            }
        }
        std::cout << "Cannot unequip materia. Too much are on the floor" << std::endl;
        return;
    }
    std::cout << "Inventory empty at index " << idx << std::endl;
}

void Character::equipFromFloor(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index. Must be between 0 and 3" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!this->_inventory[i])
        {
            if (this->_floor[idx])
            {
                this->_inventory[i]           = this->_floor[idx];
                this->_floor[idx] = NULL;
                shiftLeftMaterias(idx, this->_floor);
            }
            else if (!this->_floor[idx])
                std::cout << "Floor empty at index " << idx << std::endl;
            return;
        }
    }
    std::cout << this->_name << "'s inventory is full. Cannot equip more materia" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index. Must be between 0 and 3" << std::endl;
        return;
    }
    if (this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        return;
    }
    std::cout << "Inventory empty at index " << idx << std::endl;
}

std::string const& Character::getEquippedMateria(int idx) const
{
    static std::string empty = "";
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index. Must be between 0 and 3" << std::endl;
        return empty;
    } 
    else if (this->_inventory[idx])
        return this->_inventory[idx]->getType();
    std::cout << "Inventory empty at index " << idx << std::endl;
    return empty;
}

std::string const& Character::getUnequippedMateria(int idx) const
{
    static std::string empty = "";
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index. Must be between 0 and 3" << std::endl;
        return empty;
    } 
    else if (this->_floor[idx])
        return this->_floor[idx]->getType();
    std::cout << "Floor empty at index " << idx << std::endl;
    return empty;
}

void Character::deleteMaterias() const
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i])
        {
            std::cout << "Deleting " << this->_inventory[i]->getType() << " from "
            << this->_name << "'s inventory" << std::endl;
            delete this->_inventory[i];
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_floor[i])
        {
            std::cout << "Deleting " << this->_name << "'s materia "
            << this->_floor[i]->getType() << " left on the floor" << std::endl;
            delete this->_floor[i];
        }
    }
}

void Character::shiftLeftMaterias(int idx, AMateria** array) const
{
    for (int j = idx; j < 3; ++j)
    {
        if (array[j + 1])
        {
            array[j]     = array[j + 1];
            array[j + 1] = NULL;
        }
    }
}
