#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat& copy);
    ~Cat();

    Cat& operator=(const Cat& rhs);

    virtual void makeSound() const;
};

#endif
