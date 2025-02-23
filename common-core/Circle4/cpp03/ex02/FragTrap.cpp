#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_hitPoints    = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " was created" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    this->_name         = name;
    this->_hitPoints    = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap()
{
    this->_name         = copy._name;
    this->_hitPoints    = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    std::cout << "FragTrap " << this->_name << " (copy) was created" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " was destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
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

void FragTrap::highFiveGuys(void)
{
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
        std::cout << this->_name << " is unable to ask for a high five." << std::endl;
    else
        std::cout << this->_name << " really wants a high five!" << std::endl;
}
