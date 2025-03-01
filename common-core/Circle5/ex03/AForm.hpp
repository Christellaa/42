#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include <iostream>
class Bureaucrat;

class AForm
{
  public:
    AForm();
    AForm(const std::string& name);
    AForm(const std::string& name, const unsigned int& gradeSign, const unsigned int& gradeExec);
    AForm(const AForm& copy);
    virtual ~AForm();

    AForm& operator=(const AForm& rhs);

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
    class GradeTooLowToSignException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class IsSignedException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class GradeTooLowToExecException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    std::string const& getName() const;
    bool const&        getIsSigned() const;
    int const&         getGradeToSign() const;
    int const&         getGradeToExec() const;
    void               beSigned(const Bureaucrat& bureaucrat);
    void               execute(Bureaucrat const& executor) const;

  private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExec;
    virtual void      performAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
