#ifndef _ICE_HPP_
#define _ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    Ice(const Ice& copy);
    ~Ice();

    Ice& operator=(const Ice& rhs);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
