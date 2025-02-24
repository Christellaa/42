#include "Character.hpp"
#include "Ice.hpp"

Character::Character() : _name("default"), _slotIdx(0) {
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& copy)
{
	this->_name = copy._name;
	this->_slotIdx = copy._slotIdx;
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

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_slotIdx = rhs._slotIdx;
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

Character::Character(const std::string& name) : _name(name), _slotIdx(0)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete this->_inventory[i];
}


std::string const& Character::getName() const
{
	return this->_name;
}

void               Character::equip(AMateria* m)
{
	// to implement
}

void               Character::unequip(int idx)
{
	// to implement
}

void               Character::use(int idx, Character& target)
{
	// check which materia it is in _slot with idx
	if (this->_slotIdx != idx)
		std::cout << "" << std::endl;
	// call materia::use with target as arg
}
