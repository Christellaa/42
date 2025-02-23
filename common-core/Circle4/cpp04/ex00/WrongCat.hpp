#ifndef _WRONGCAT_HPP_
#define _WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
    WrongCat();
    WrongCat(const WrongCat& copy);
    ~WrongCat();

    WrongCat& operator=(const WrongCat& rhs);

    virtual void makeSound() const;
};

#endif
