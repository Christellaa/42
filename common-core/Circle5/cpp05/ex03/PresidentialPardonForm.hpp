#ifndef _PRESIDENTIALPARDONFORM_HPP_
#define _PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

    void performAction() const;

  private:
    PresidentialPardonForm();
    const std::string _target;
};

#endif
