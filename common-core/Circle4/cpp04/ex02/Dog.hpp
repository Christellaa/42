#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
  public:
    Dog();
    Dog(const Dog& copy);
    ~Dog();

    Dog& operator=(const Dog& rhs);

    virtual void makeSound() const;
    Brain&       getBrain() const;

  private:
    Brain* _brain;
};

#endif
