#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name(ClapTrap::_name)
{
    ScavTrap::setScavEnergyPoints(50);
    this->_name         = ClapTrap::_name + "_clap_name";
    this->_hitPoints    = _hitPoints;
    this->_energyPoints = _energyPoints;
    this->_attackDamage = _attackDamage;
    std::cout << "DiamondTrap " << this->_name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name)
{
    ScavTrap::setScavEnergyPoints(50);
    this->_name         = ClapTrap::_name + "_clap_name";
    this->_hitPoints    = _hitPoints;
    this->_energyPoints = _energyPoints;
    this->_attackDamage = _attackDamage;
    std::cout << "DiamondTrap " << this->_name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    this->_name         = copy._name;
    this->_hitPoints    = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    std::cout << "DiamondTrap " << this->_name << " (copy) was created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " was destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->_name         = rhs._name;
        this->_hitPoints    = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << this->_name << " is my name! But it is also " << ClapTrap::_name << std::endl;
}
