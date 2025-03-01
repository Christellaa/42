#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    (void) copy;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void) rhs;
    return *this;
}

const char* Intern::MakeFormException::what() const throw()
{
    return ("Form name passed as first parameter doesn't exist");
}

AForm* Intern::makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    const std::string _formName[3]             = {"shrubbery creation", "robotomy request",
                                                  "presidential pardon"};
    AForm* (*formArray[3])(const std::string&) = {&Intern::makeShrubbery, &Intern::makeRobotomy,
                                                  &Intern::makePresidentialPardon};
    for (int i = 0; i < 3; ++i)
    {
        if (formName == _formName[i])
        {
            std::cout << "Intern creates " << _formName[i] << std::endl;
            return (*formArray[i])(target);
        }
    }
    throw MakeFormException();
}
