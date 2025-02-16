#include "PhoneBook.hpp"
#include "includes.h"

void commandInfo(void)
{
    std::cout << YELLOW << "Command Info:" << std::endl;
    std::cout << "ADD: add a contact to the phonebook" << std::endl;
    std::cout << "SEARCH: search for a contact in the phonebook" << std::endl;
    std::cout << "EXIT: quit the program" << RESET << std::endl;
}

std::string truncateWord(std::string word)
{
    std::string truncated;

    truncated = word.substr(0, 10);
    if (word.length() > 10)
        truncated[9] = '.';
    return truncated;
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
