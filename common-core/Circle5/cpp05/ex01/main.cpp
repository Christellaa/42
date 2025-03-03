#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "Constructor with too high grade:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat test1("test1", 0);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Constructor with too low grade:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat test2("test2", 151);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Increment grade until exception:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat test3("test3", 1);
            std::cout << test3 << std::endl;
            test3.incrementGrade();
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Decrement grade until exception:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat test4;
            std::cout << test4 << std::endl;
            test4.decrementGrade();
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Everything working:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat test5("test5", 55);
            std::cout << test5 << std::endl;
            test5.decrementGrade();
            std::cout << test5 << std::endl;
            test5.decrementGrade();
            std::cout << test5 << std::endl;
            test5.decrementGrade();
            std::cout << test5 << std::endl;
            test5.incrementGrade();
            std::cout << test5 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Increment copy and copy2 (must have different value at the end):" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Bureaucrat test("test");
            Bureaucrat copy(test);
            Bureaucrat copy2(copy);
            copy.incrementGrade();
            copy2.incrementGrade();
            copy2.incrementGrade();
            std::cout << test << std::endl;
            std::cout << copy << std::endl;
            std::cout << copy2 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Form working:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form;
            std::cout << form << std::endl;
            Bureaucrat bureaucrat("bureaucrat", 1);
            std::cout << bureaucrat << std::endl;
            bureaucrat.signForm(form);
            std::cout << form << std::endl;
            bureaucrat.signForm(form);
            std::cout << form << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Grade too low to sign form:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form("form", 5, 5);
            std::cout << form << std::endl;
            Bureaucrat bureaucrat("bureaucrat", 6);
            std::cout << bureaucrat << std::endl;
            bureaucrat.signForm(form);
            std::cout << form << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Form constructor has gradeToSign too high:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form("form", -2, 5);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "----------" << std::endl;
    std::cout << "Form constructor has gradeToSign too low:" << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form("form", 555, 5);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
