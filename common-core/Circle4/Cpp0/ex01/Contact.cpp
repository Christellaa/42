#include "Contact.hpp"
#include "includes.h"

void Contact::setFirstName(void) noexcept
{
	std::string fName;
	std::getline(std::cin, fName);
	this->_firstName = fName;
}

void Contact::setLastName(void) noexcept
{
	std::string lName;
	std::getline(std::cin, lName);
	this->_lastName = lName;
}

void Contact::setNickName(void) noexcept
{
	std::string nName;
	std::getline(std::cin, nName);
	this->_nickName = nName;
}

void Contact::setPhone(void) noexcept
{
	std::string phone;
	std::getline(std::cin, phone);
	this->_phone = phone;
}

void Contact::setSecret(void) noexcept
{
	std::string secret;
	std::getline(std::cin, secret);
	this->_secret = secret;
}
