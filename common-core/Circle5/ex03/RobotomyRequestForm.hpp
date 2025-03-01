#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

    class FailRobotomyException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    void performAction() const;

  private:
    RobotomyRequestForm();
    const std::string _target;
};

#endif
