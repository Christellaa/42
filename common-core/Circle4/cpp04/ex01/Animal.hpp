#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <iostream>

class Animal
{
  public:
    Animal();
    Animal(const Animal& copy);
    virtual ~Animal();

    Animal& operator=(const Animal& rhs);

    virtual void       makeSound() const;
    std::string const& getType() const;

  protected:
    std::string _type;
};

#endif
