#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default bureaucrat"), _grade(150)
{
    std::cout << this->_name << "'s constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150)
{
    std::cout << this->_name << "'s constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
    : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw GradeTooHighException();
    else if (this->_grade > 150)
        throw GradeTooLowException();
    std::cout << this->_name << "'s constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << this->_name << "'s copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->_name << "'s destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat: Grade is too low");
}

std::string const& Bureaucrat::getName() const
{
    return this->_name;
}

int const& Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::signForm(Form& form)
{
    if (form.getSigned())
    {
        std::cout << this->_name << " has already signed " << form.getName() << std::endl;
        return;
    }
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw GradeTooHighException();
    this->_grade--;
}
void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw GradeTooLowException();
    this->_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
