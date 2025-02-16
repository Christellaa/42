#include "PhoneBook.hpp"
#include "includes.h"

void commandInfo(void)
{
    std::cout << YELLOW << "Command Info:" << std::endl;
    std::cout << "ADD: add a contact to the phonebook" << std::endl;
    std::cout << "SEARCH: search for a contact in the phonebook" << std::endl;
    std::cout << "EXIT: quit the program" << RESET << std::endl;
}

int main(void)
{
    PhoneBook phonebook;
    commandInfo();
    while (1)
    {
        std::cout << "> ";
        std::string command;
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            // std::cout << "searchContact() to do" << std::endl;
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else if (command != "\0")
        {
            std::cout << RED << "Invalid command." << RESET << std::endl;
            commandInfo();
        }
    }
}
