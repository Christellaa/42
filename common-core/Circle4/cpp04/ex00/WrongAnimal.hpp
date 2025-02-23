#ifndef _WRONGANIMAL_H_
#define _WRONGANIMAL_H_

#include <iostream>

class WrongAnimal
{
  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& copy);
    virtual ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& rhs);

    virtual void       makeSound() const;
    std::string const& getType() const;

  protected:
    std::string _type;
};

#endif
