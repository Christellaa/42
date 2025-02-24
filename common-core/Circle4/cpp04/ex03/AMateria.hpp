#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_

#include <iostream>
class ICharacter;

class AMateria
{
  public:
    AMateria();
    AMateria(std::string const& type);
    AMateria(const AMateria& copy);
    virtual ~AMateria();

    AMateria& operator=(const AMateria& rhs);

    std::string const& getType() const;
    virtual AMateria*  clone() const = 0;
    virtual void       use(ICharacter& target);

  protected:
    std::string _type;
};

#endif
