#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <iostream>
class Bureaucrat;

class Form
{
  public:
    Form();
    Form(const std::string& name);
    Form(const std::string& name, const unsigned int& gradeSign, const unsigned int& gradeExec);
    Form(const Form& copy);
    ~Form();

    Form& operator=(const Form& rhs);

    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    std::string const& getName() const;
    bool const&        getSigned() const;
    int const&         getGradeToSign() const;
    int const&         getGradeToExec() const;
    void               beSigned(const Bureaucrat& bureaucrat);

  private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExec;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
