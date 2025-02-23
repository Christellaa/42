#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal
{
  public:
    Dog();
    Dog(const Dog& copy);
    ~Dog();

    Dog& operator=(const Dog& rhs);

    virtual void makeSound() const;
};

#endif
