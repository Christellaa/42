#include "PhoneBook.hpp"
#include "includes.h"

void PhoneBook::addContact() noexcept
{
	// - check if any field is empty, if so
	//		-> fail it and go back to user input (add, search...)
	if (_idx < 8)
	{
		std::cout << "FirstName: ";
		_contact[_idx].setFirstName();
		std::cout << "LastName: ";
		_contact[_idx].setLastName();
		std::cout << "NickName: ";
		_contact[_idx].setNickName();
		std::cout << "PhoneNumber: ";
		_contact[_idx].setPhone();
		std::cout << "DarkestSecret: ";
		_contact[_idx].setSecret();
		_idx++;
	}
	else
		std::cout << "replace last contact with the new one" << std::endl;
}
