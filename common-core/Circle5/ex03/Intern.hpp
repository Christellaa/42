#ifndef _INTERN_HPP
#define _INTERN_HPP

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

    AForm* makeForm(const std::string& s1, const std::string& s2);

  private:
    static AForm* makeShrubbery(const std::string& target);
    static AForm* makeRobotomy(const std::string& target);
    static AForm* makePresidentialPardon(const std::string& target);
};

#endif
