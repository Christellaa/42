#ifndef _SCAVTRAP_H_
#define _SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& copy);
    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& rhs);

    void attack(const std::string& target);
    void guardGate();

  private:
    bool _guardMode;
};

#endif
