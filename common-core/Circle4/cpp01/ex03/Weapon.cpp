#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& weapon) : _type(weapon) {}

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}

std::string const& Weapon::getType() const
{
	return this->_type;
}
