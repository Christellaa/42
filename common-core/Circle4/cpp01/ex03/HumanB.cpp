#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL){};

void HumanB::attack() const
{
    if (!this->_weapon)
        std::cout << this->_name << " attacks with only his hands... He forgot to take a weapon!"
                  << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}
