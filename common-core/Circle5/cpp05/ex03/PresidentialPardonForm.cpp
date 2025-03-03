#include "PresidentialPardonForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default shrubbery creation form", 25, 5), _target("default target")
{
    std::cout << this->_target << "'s constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, 25, 5), _target(target)
{
    std::cout << this->_target << "'s constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm(), _target(copy._target)
{
    std::cout << this->_target << "'s copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << this->_target << "'s destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    (void) rhs;
    return *this;
}

void PresidentialPardonForm::performAction() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
