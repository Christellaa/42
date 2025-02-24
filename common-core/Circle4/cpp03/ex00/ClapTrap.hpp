#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
  public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& copy);

    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& rhs);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  private:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif
