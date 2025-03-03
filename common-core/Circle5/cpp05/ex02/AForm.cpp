#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default form"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
    std::cout << this->_name << "'s constructor called" << std::endl;
}

AForm::AForm(const std::string& name)
    : _name(name), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
    std::cout << this->_name << "'s constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const unsigned int& gradeSign, const unsigned int& gradeExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
    if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
        throw GradeTooHighException();
    else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << this->_name << "'s constructor called" << std::endl;
}
AForm::AForm(const AForm& copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign),
      _gradeToExec(copy._gradeToExec)
{
    std::cout << this->_name << "'s copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << this->_name << "'s destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high for the form, Must be between 1 and 150");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low for the form. Must be between 1 and 150");
}

const char* AForm::GradeTooLowToSignException::what() const throw()
{
    return ("Grade is too low to sign the form");
}

const char* AForm::IsSignedException::what() const throw()
{
    return ("Form isn't signed");
}

const char* AForm::GradeTooLowToExecException::what() const throw()
{
    return ("Grade is too low to execute the form");
}

std::string const& AForm::getName() const
{
    return this->_name;
}

bool const& AForm::getIsSigned() const
{
    return this->_isSigned;
}

int const& AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int const& AForm::getGradeToExec() const
{
    return this->_gradeToExec;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw GradeTooLowToSignException();
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!this->_isSigned)
        throw IsSignedException();
    else if (executor.getGrade() > this->_gradeToExec)
        throw GradeTooLowToExecException();
    performAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << form.getName() << ", form grade to sign it: " << form.getGradeToSign()
        << ", grade to execute it: " << form.getGradeToExec()
        << ", is signed: " << form.getIsSigned();
    return out;
}
