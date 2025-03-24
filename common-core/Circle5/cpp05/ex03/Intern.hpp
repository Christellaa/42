#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include "AForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(const Intern& copy);
    ~Intern();

    Intern& operator=(const Intern& rhs);

    class MakeFormException : public std::exception
    {
        const char* what() const throw();
    };

    AForm* makeForm(const std::string& formName, const std::string& formTarget);

  private:
    static AForm* makeShrubbery(const std::string& target);
    static AForm* makeRobotomy(const std::string& target);
    static AForm* makePresidentialPardon(const std::string& target);
};

#endif
