#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default form"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
    std::cout << this->_name << "'s constructor called" << std::endl;
}

Form::Form(const std::string& name)
    : _name(name), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
    std::cout << this->_name << "'s constructor called" << std::endl;
}

Form::Form(const std::string& name, const unsigned int& gradeSign, const unsigned int& gradeExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
        throw GradeTooHighException();
    else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << this->_name << "'s constructor called" << std::endl;
}
Form::Form(const Form& copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign),
      _gradeToExec(copy._gradeToExec)
{
    std::cout << this->_name << "'s copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << this->_name << "'s destructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form: Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form: Grade is too low");
}

std::string const& Form::getName() const
{
    return this->_name;
}

bool const& Form::getIsSigned() const
{
    return this->_isSigned;
}

int const& Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int const& Form::getGradeToExec() const
{
    return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw GradeTooLowException();
    this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << ", form grade to sign it: " << form.getGradeToSign()
        << ", grade to execute it: " << form.getGradeToExec()
        << ", is signed: " << form.getIsSigned();
    return out;
}
