#include "PhoneBook.hpp"
#include "includes.h"
#include <iomanip>

PhoneBook::PhoneBook()
{
    _idx = 0;
}

bool PhoneBook::setFields(int _idx)
{
    Contact copy = _contact[_idx];
    std::cout << BLUE << "First name: " << RESET;
    _contact[_idx].setFirstName();
    std::cout << BLUE << "Last name: " << RESET;
    _contact[_idx].setLastName();
    std::cout << BLUE << "Nickname: " << RESET;
    _contact[_idx].setNickName();
    std::cout << BLUE << "Phone number: " << RESET;
    _contact[_idx].setPhone();
    std::cout << BLUE << "Darkest secret: " << RESET;
    _contact[_idx].setSecret();
    if (!areFieldsFilled(_contact[_idx]))
    {
        std::cout << YELLOW << "At least one field is empty. Contact will not be saved." << RESET
                  << std::endl;
        _contact[_idx] = copy;
        return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    if (!setFields(_idx))
        return;
    _idx = (_idx + 1) % 8;
}

void PhoneBook::printAllContacts() const
{
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│" << std::setw(10) << "Index";
    std::cout << "│" << std::setw(10) << "First name";
    std::cout << "│" << std::setw(10) << "Last name";
    std::cout << "│" << std::setw(10) << "Nickname"
              << "│" << std::endl;
    for (int idx = 0; idx < 8 && areFieldsFilled(_contact[idx]); ++idx)
    {
        std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
        std::cout << "│" << std::setw(10) << idx;
        std::cout << "│" << std::setw(10) << truncateWord(_contact[idx].getFirstName());
        std::cout << "│" << std::setw(10) << truncateWord(_contact[idx].getLastName());
        std::cout << "│" << std::setw(10) << truncateWord(_contact[idx].getNickName()) << "│"
                  << std::endl;
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void PhoneBook::printContact(int idx) const
{
    std::cout << YELLOW << "First name: " << RESET << _contact[idx].getFirstName() << std::endl;
    std::cout << YELLOW << "Last name: " << RESET << _contact[idx].getLastName() << std::endl;
    std::cout << YELLOW << "Nickname: " << RESET << _contact[idx].getNickName() << std::endl;
    std::cout << YELLOW << "Phone number: " << RESET << _contact[idx].getPhone() << std::endl;
    std::cout << YELLOW << "Darkest secret: " << RESET << _contact[idx].getSecret() << std::endl;
}

void PhoneBook::searchContact() const
{
    if (!areFieldsFilled(_contact[0]))
    {
        std::cout << YELLOW << "Empty phone book." << RESET << std::endl;
        return;
    }
    printAllContacts();
    std::cout << BLUE << "Choose an index to print a specific contact: " << RESET;
    std::string index;
    while (true)
    {
        std::getline(std::cin, index);
        if (index.length() == 1 && index[0] >= '0' && index[0] <= '9')
        {
            int idx = index[0] - '0';
            if (idx < 8 && areFieldsFilled(_contact[idx]))
                return printContact(idx);
            else
                std::cout << RED << "No contact found at index: " << idx << ". ";
        }
        else
            std::cout << RED << "Invalid index. ";
        std::cout << BLUE << "Choose a valid index: " << RESET;
    }
}
