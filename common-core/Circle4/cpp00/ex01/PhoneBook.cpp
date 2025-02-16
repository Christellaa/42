#include "PhoneBook.hpp"
#include "includes.h"

PhoneBook::PhoneBook()
{
    _idx = 0;
}

bool areFieldsFilled(const Contact& contact)
{
    return (!contact.getFirstName().empty() && !contact.getLastName().empty() &&
            !contact.getNickName().empty() && !contact.getPhone().empty() &&
            !contact.getSecret().empty());
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
        std::cout << "At least one field is empty. Contact will not be saved." << std::endl;
        _contact[_idx] = copy;
        return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    std::cout << "current idx: " << _idx << std::endl; // debug
    if (!setFields(_idx))
        return;
    _idx = (_idx + 1) % 8;
}

void PhoneBook::searchContact()
{
    /*
    - display all contacts as a list of 4 cols -> idx, firstname, lastname, nickname
    - prompt the user for the idx of the contact to display
        - out of range idx = prompt again
        - good idx = display contact info, one field per line
    COL
    - 10 chars wide
    - | between each col
    TEXT
    - right-aligned
    - more than col width = trunc and last char replaced by .
    */
}
