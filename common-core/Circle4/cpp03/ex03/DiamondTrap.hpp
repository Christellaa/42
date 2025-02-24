#ifndef _DIAMONDTRAP_HPP_
#define _DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& copy);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& rhs);
    void         attack(const std::string& target);
    void         whoAmI();

  private:
    std::string _name;
};

#endif
