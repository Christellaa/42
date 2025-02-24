#include "Character.hpp"
#include "Ice.hpp"

Character::Character() : _name("default")
{
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 4; ++i)
        this->_unequippedMateria[i] = NULL;
}

Character::Character(const Character& copy)
{
    this->_name = copy._name;
    for (int i = 0; i < 4; ++i)
        delete this->_inventory[i];
    for (int i = 0; i < 4; ++i)
        delete this->_unequippedMateria[i];
    for (int i = 0; i < 4; ++i)
    {
        if (copy._inventory[i] != NULL)
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character::Character(const std::string& name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 4; ++i)
        this->_unequippedMateria[i] = NULL;
}

Character::~Character()
{
    std::cout << "Destroying Character..." << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i])
        {
            std::cout << "Deleting materia from inventory..." << std::endl;
            delete this->_inventory[i];
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_unequippedMateria[i])
        {
            std::cout << "Deleting unequipped materia..." << std::endl;
            delete this->_unequippedMateria[i];
        }
    }
}

Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; ++i)
            delete this->_inventory[i];
        for (int i = 0; i < 4; ++i)
            delete this->_unequippedMateria[i];
        for (int i = 0; i < 4; ++i)
        {
            if (rhs._inventory[i] != NULL)
                this->_inventory[i] = rhs._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
            if (rhs._unequippedMateria[i] != NULL)
                this->_unequippedMateria[i] = rhs._unequippedMateria[i]->clone();
            else
                this->_unequippedMateria[i] = NULL;
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
        else if (i == 3)
        {
            std::cout << "Cannot equip more materia. Inventory is full" << std::endl;
            return;
        }
    }
    std::cout << "Materia does not exist" << std::endl;
}

void Character::unequip(int idx)
{
    if (this->_inventory[idx])
    {
        for (int i = 0; i < 4; ++i)
        {
            if (!this->_unequippedMateria[i])
            {
                this->_unequippedMateria[i] = this->_inventory[idx];
                this->_inventory[idx]       = NULL;
            }
            else if (i == 3)
            {
                std::cout << "Cannot remove more materia. Too much are on the floor" << std::endl;
                return;
            }
        }
        return;
    }
    std::cout << "Invalid index. cannot find materia in " << this->_name << "'s inventory"
              << std::endl;
}

void Character::equipFromFloor(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index. Cannot find unequipped materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!this->_inventory[i])
        {
            if (this->_unequippedMateria[idx])
            {
                this->_inventory[i]           = this->_unequippedMateria[idx];
                this->_unequippedMateria[idx] = NULL;
                for (int j = idx; j < 3; ++j)
                {
                    if (this->_unequippedMateria[j + 1])
                    {
                        this->_unequippedMateria[j]     = this->_unequippedMateria[j + 1];
                        this->_unequippedMateria[j + 1] = NULL;
                    }
                }
            }
            return;
        }
    }
    std::cout << "Cannot equip more materia" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        return;
    }
    std::cout << "Invalid index. Cannot find materia in " << this->_name << "'s inventory"
              << std::endl;
}
