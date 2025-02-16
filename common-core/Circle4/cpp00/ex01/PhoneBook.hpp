#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "includes.h"

class PhoneBook
{
  public:
    PhoneBook();          // = construct
    void addContact();    // = setter
    void searchContact(); // = getter

  private:
    int _idx;
    bool setFields(int _idx);
    Contact _contact[8];
};

#endif
