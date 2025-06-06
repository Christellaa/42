#include "Contact.hpp"
#include "includes.h"

void Contact::setFirstName(void)
{
    std::string fName;
    std::getline(std::cin, fName);
    this->_firstName = fName;
}

void Contact::setLastName(void)
{
    std::string lName;
    std::getline(std::cin, lName);
    this->_lastName = lName;
}

void Contact::setNickName(void)
{
    std::string nName;
    std::getline(std::cin, nName);
    this->_nickName = nName;
}

void Contact::setPhone(void)
{
    std::string phone;
    std::getline(std::cin, phone);
    this->_phone = phone;
}

void Contact::setSecret(void)
{
    std::string secret;
    std::getline(std::cin, secret);
    this->_secret = secret;
}

std::string const& Contact::getFirstName() const
{
    return this->_firstName;
}

std::string const& Contact::getLastName() const
{
    return this->_lastName;
}

std::string const& Contact::getNickName() const
{
    return this->_nickName;
}

std::string const& Contact::getPhone() const
{
    return this->_phone;
}

std::string const& Contact::getSecret() const
{
    return this->_secret;
}

bool areFieldsFilled(const Contact& contact)
{
    return (!contact.getFirstName().empty() && !contact.getLastName().empty() &&
            !contact.getNickName().empty() && !contact.getPhone().empty() &&
            !contact.getSecret().empty());
}
