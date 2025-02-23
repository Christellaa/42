#ifndef _AANIMAL_HPP_
#define _AANIMAL_HPP_

#include <iostream>

class AAnimal
{
  public:
    AAnimal();
    AAnimal(const AAnimal& copy);
    virtual ~AAnimal();

    AAnimal& operator=(const AAnimal& rhs);

    virtual void       makeSound() const = 0;
    std::string const& getType() const;

  protected:
    std::string _type;
};

#endif
