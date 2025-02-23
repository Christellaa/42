#ifndef _FRAGTRAP_H_
#define _FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
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
