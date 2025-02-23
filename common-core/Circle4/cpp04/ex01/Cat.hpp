#ifndef _CAT_H_
#define _CAT_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat& copy);
    ~Cat();

    Cat& operator=(const Cat& rhs);

    virtual void makeSound() const;
    Brain&       getBrain() const;

  private:
    Brain* _brain;
};

#endif
