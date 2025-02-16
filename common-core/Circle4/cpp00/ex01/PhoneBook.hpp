#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "includes.h"

class PhoneBook
{
  public:
    PhoneBook();
    void addContact();
    void searchContact() const;

  private:
    int _idx;
    bool setFields(int _idx);
    void printAllContacts() const;
    void printContact(int idx) const;
    Contact _contact[8];
};

#endif
