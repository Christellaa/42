#include "PhoneBook.hpp"
#include "includes.h"

int	main(void)
{
	PhoneBook phonebook{};
	std::cout << "COMMAND INFO:" << std::endl;
	std::cout << "ADD: add a contact to the phonebook" << std::endl;
	std::cout << "Search: search for a contact in the phonebook" << std::endl;
	std::cout << "EXIT: quit the program" << std::endl;
	while (1)
	{
		std::string command;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			std::cout << "searchContact() to do" << std::endl;
		else if (command == "EXIT")
			break ;
	}
}
