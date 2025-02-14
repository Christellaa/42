#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "includes.h"

class PhoneBook
{
  public:
    PhoneBook();
    void addContact(); // = setter

    // void search_contact();
    // = getter

  private:
    int _idx;
    bool setFields(int _idx);
    Contact _contact[8];
};

#endif
