#ifndef _FRAGTRAP_HPP_
#define _FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& copy);
    ~FragTrap();

    FragTrap& operator=(const FragTrap& rhs);
    void      highFiveGuys(void);
};

#endif
