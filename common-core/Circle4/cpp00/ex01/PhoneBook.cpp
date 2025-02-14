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
    std::cout << BLUE << "FirstName: " << RESET;
    _contact[_idx].setFirstName();
    std::cout << BLUE << "LastName: " << RESET;
    _contact[_idx].setLastName();
    std::cout << BLUE << "NickName: " << RESET;
    _contact[_idx].setNickName();
    std::cout << BLUE << "PhoneNumber: " << RESET;
    _contact[_idx].setPhone();
    std::cout << BLUE << "DarkestSecret: " << RESET;
    _contact[_idx].setSecret();
    if (!areFieldsFilled(_contact[_idx]))
    {
        std::cout << "At least one field is empty, the contact will not be saved" << std::endl;
        // if field is empty when replacing last contact, we should keep last contact => copy of
        // last contact, replace last contact, if failed take copy, otherwise delete copy ???
        _contact[_idx].resetFields();
        return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    if (!setFields(_idx))
        return;
    if (_idx < 7)
        _idx++;
}
