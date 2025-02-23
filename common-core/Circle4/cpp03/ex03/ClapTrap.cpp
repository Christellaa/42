#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    this->_name         = copy._name;
    this->_hitPoints    = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    std::cout << "ClapTrap " << this->_name << " (copy) was created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " was destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this != &rhs)
    {
        this->_name         = rhs._name;
        this->_hitPoints    = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
        std::cout << this->_name
                  << " can't really attack... because it kind of can't get up... it's dead."
                  << std::endl;
    else if (this->_energyPoints == 0)
        std::cout << this->_name << " is too tired! Let it rest, it can't move anymore!"
                  << std::endl;
    else
    {
        this->_energyPoints--;
        std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage
                  << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
        std::cout << "Why are you still attacking a dead ClapTrap...? Leave " << this->_name
                  << " alone." << std::endl;
    else
    {
        if (amount > this->_hitPoints)
            this->_hitPoints = 0;
        else
            this->_hitPoints -= amount;
        std::cout << this->_name << " got attacked and took " << amount
                  << " points of damage! It now has " << this->_hitPoints << " hit points!"
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        if (this->_hitPoints + amount >= 10)
            this->_hitPoints = 10;
        else
            this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << this->_name << " repaired itself, regaining " << amount
                  << " hit points! It now has " << this->_hitPoints << " hit points!" << std::endl;
    }
    else if (this->_hitPoints == 0)
        std::cout
            << this->_name
            << " is kind of unable to repair itself... It's not coming back from the dead, sorry."
            << std::endl;
    else if (this->_energyPoints == 0)
        std::cout << this->_name << " has no more energy points to spend!" << std::endl;
}
