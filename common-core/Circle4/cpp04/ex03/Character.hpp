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
    void               use(int idx, Character& target);

	private:
		std::string _name;
		AMateria  	*_inventory[4];
		int 		_slotIdx;
};

#endif
