#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
class Form;

class Bureaucrat
{
  public:
    Bureaucrat();
    Bureaucrat(const std::string& name);
    Bureaucrat(const std::string& name, const unsigned int& grade);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& rhs);

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
    int const&         getGrade() const;
    void               signForm(Form& form);

    void incrementGrade();
    void decrementGrade();

  private:
    const std::string _name;
    int               _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
