#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "ICharacter.hpp"

class Character : public ICharacter
{
  public:
    Character();
    Character(const Character& copy);
    Character(const std::string& name);
    ~Character();

    Character& operator=(const Character& rhs);

    std::string const& getName() const;
    void               equip(AMateria* m);
    void               unequip(int idx);
    void               equipFromFloor(int idx);
    void               use(int idx, ICharacter& target);
    std::string const& getEquippedMateria(int idx) const;
    std::string const& getUnequippedMateria(int idx) const;

  private:
    std::string _name;
    AMateria*   _inventory[4];
    AMateria*   _floor[4];
    void        deleteMaterias() const;
    void        shiftLeftMaterias(int idx, AMateria** m) const;
};

#endif
