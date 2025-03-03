#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

    class OpenFileException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    void performAction() const;

  private:
    ShrubberyCreationForm();
    const std::string _target;
};

#endif
