#ifndef _DOG_H_
#define _DOG_H_

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
