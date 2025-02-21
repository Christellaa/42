#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include "Weapon.h"

class Weapon
{
  public:
    Weapon();
    Weapon(const std::string& weapon);

    void               setType(const std::string& type);
    std::string const& getType(void) const;

  private:
    std::string _type;
};

#endif
