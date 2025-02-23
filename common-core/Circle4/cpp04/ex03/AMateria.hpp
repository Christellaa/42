#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
  public:
    AMateria(std::string const& type);
    // +?
    AMateria();
    AMateria(const AMateria& copy);
    ~AMateria();

    AMateria& operator=(const AMateria& rhs);

    // implement in Ice and Cure to create new instance of same
    virtual AMateria* clone() const = 0;
    virtual void      use(ICharacter& target);

  protected:
    std::string _type;
};

#endif
