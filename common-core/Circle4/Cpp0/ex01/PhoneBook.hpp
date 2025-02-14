#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include "includes.h"

class PhoneBook
{
  public:
	void addContact() noexcept; // = setter

	// void search_contact();
	// = getter

  private:
	int _idx = 0;
	std::array<Contact, 7> _contact;
};

#endif
