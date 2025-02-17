#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include "Zombie.h"

class Zombie
{
  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce();
    void setName(std::string name);

  private:
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
