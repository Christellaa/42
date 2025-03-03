#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

int main()
{
    // seed the random number generator using current time
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "SHRUBBERY TESTS:" << std::endl;
    std::cout << "Form unsigned:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat            test1("test1", 100);
            ShrubberyCreationForm form("home");
            std::cout << test1 << std::endl;
            std::cout << form << std::endl;
            test1.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Too low grade:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat            test2("test2", 138);
            ShrubberyCreationForm form("home");
            std::cout << test2 << std::endl;
            std::cout << form << std::endl;
            test2.signForm(form);
            std::cout << form << std::endl;
            test2.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Execute shrubbery:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat            test3("test3", 137);
            ShrubberyCreationForm form("home");
            std::cout << test3 << std::endl;
            std::cout << form << std::endl;
            test3.signForm(form);
            std::cout << form << std::endl;
            test3.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "ROBOTOMY TESTS:" << std::endl;
    std::cout << "Form unsigned:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat          test1("test1", 88);
            RobotomyRequestForm form("home");
            std::cout << test1 << std::endl;
            std::cout << form << std::endl;
            test1.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Too low grade:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat          test2("test2", 57);
            RobotomyRequestForm form("home");
            std::cout << test2 << std::endl;
            std::cout << form << std::endl;
            test2.signForm(form);
            std::cout << form << std::endl;
            test2.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Execute robotomy:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat          test4("test4", 33);
            RobotomyRequestForm form("test41");
            std::cout << test4 << std::endl;
            std::cout << form << std::endl;
            test4.signForm(form);
            std::cout << form << std::endl;
            test4.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "PRESIDENTIAL PARDON TESTS:" << std::endl;
    std::cout << "Form unsigned:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat             test1("test1", 55);
            PresidentialPardonForm form("home");
            std::cout << test1 << std::endl;
            std::cout << form << std::endl;
            test1.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Too low grade:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat             test2("test2", 6);
            PresidentialPardonForm form("home");
            std::cout << test2 << std::endl;
            std::cout << form << std::endl;
            test2.signForm(form);
            std::cout << form << std::endl;
            test2.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Execute presidential pardon:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat             test5("test5", 2);
            PresidentialPardonForm form("pardonMePlease");
            std::cout << test5 << std::endl;
            std::cout << form << std::endl;
            test5.signForm(form);
            std::cout << form << std::endl;
            test5.executeForm(form);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
