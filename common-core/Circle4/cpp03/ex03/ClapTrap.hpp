#ifndef _CLAP_TRAP_HPP_
#define _CLAP_TRAP_HPP_

#include <iostream>

class ClapTrap
{
  public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& copy);

    virtual ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& rhs);

    virtual void attack(const std::string& target);
    void         takeDamage(unsigned int amount);
    void         beRepaired(unsigned int amount);

  protected:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif
