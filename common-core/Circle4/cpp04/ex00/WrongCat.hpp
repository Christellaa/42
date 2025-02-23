#ifndef _WRONGCAT_H_
#define _WRONGCAT_H_

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
