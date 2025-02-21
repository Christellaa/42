#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_

#include "Weapon.hpp"

class HumanA
{
  public:
    HumanA(const std::string& name, Weapon& weapon);

    void attack() const;

  private:
    const std::string _name;
    Weapon&           _weapon;
};

#endif
