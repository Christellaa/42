#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("default shrubbery creation form", 72, 45), _target("default target")
{
    std::cout << this->_target << "'s constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, 72, 45), _target(target)
{
    std::cout << this->_target << "'s constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(), _target(copy._target)
{
    std::cout << this->_target << "'s copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << this->_target << "'s destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    (void) rhs;
    return *this;
}

const char* RobotomyRequestForm::FailRobotomyException::what() const throw()
{
    return ("The robotomy failed");
}

void RobotomyRequestForm::performAction() const
{
    std::cout << "* drilling noises *" << std::endl;
    int number = rand() % 2;
    if (number == 1)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        throw FailRobotomyException();
}
