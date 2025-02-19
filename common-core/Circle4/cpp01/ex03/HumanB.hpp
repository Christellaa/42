#ifndef _HUMANB_HPP_
#define _HUMANB_HPP_

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string& name);

		void attack() const;
		void setWeapon(Weapon &weapon);

	private:
		const std::string _name;
		Weapon *_weapon;
};

#endif
