#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_hitPoints    = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardMode    = 0;
    std::cout << "ScavTrap " << this->_name << " was created" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
    this->_name         = name;
    this->_hitPoints    = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardMode    = 0;
    std::cout << "ScavTrap " << this->_name << " was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap()
{
    this->_name         = copy._name;
    this->_hitPoints    = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    this->_guardMode    = copy._guardMode;
    std::cout << "ScavTrap " << this->_name << " (copy) was created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " was destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this != &rhs)
    {
        this->_name         = rhs._name;
        this->_hitPoints    = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
        this->_guardMode    = rhs._guardMode;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
        std::cout
            << this->_name
            << " isn't paid enough for this. Well, he won't be paid anymore since he's dead now."
            << std::endl;
    else if (this->_energyPoints == 0)
        std::cout << this->_name
                  << " is too tired! Give him some energy drinks so it can be cool again!"
                  << std::endl;
    else
    {
        this->_energyPoints--;
        std::cout << this->_name << " attacks with style " << target << ", causing "
                  << this->_attackDamage << " points of damage! Go for it!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
        std::cout << this->_name << " is unable to enter guard mode" << std::endl;
    else
    {
        if (this->_guardMode == 0)
        {
            this->_guardMode = 1;
            std::cout << this->_name << " has entered guard mode" << std::endl;
        }
        else
            std::cout << this->_name << " is already in guard mode" << std::endl;
    }
}

void ScavTrap::setScavEnergyPoints(unsigned int number)
{
    this->_energyPoints = number;
}
