#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

int main()
{
    std::cout << "Form name doesn't exist:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Intern intern;
            intern.makeForm("no idea", "his friend");
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Form name exists:" << std::endl;
    std::cout << std::endl;
    { // "shrubbery creation", "robotomy request", "presidential pardon" are valid
        try
        {
            Intern intern;
            AForm* form = intern.makeForm("shrubbery creation", "intern");
            std::cout << *form << std::endl;
            AForm* form2 = intern.makeForm("robotomy request", "intern41");
            std::cout << *form2 << std::endl;
            AForm* form3 = intern.makeForm("presidential pardon", "president");
            std::cout << *form3 << std::endl;
            Bureaucrat bureaucrat("bureaucrat", 1);
            form2->beSigned(bureaucrat);
            form2->execute(bureaucrat);
            delete form;
            delete form2;
            delete form3;
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
