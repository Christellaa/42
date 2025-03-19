#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(0));
    int number = std::rand() % 3;
    std::cout << "Generated number: " << number << std::endl;
    Base *base;
    switch (number)
    {
    case 0:
        base = new A();
        break;
    case 1:
        base = new B();
        break;
    case 2:
        base = new C();
        break;
    }
    return base;
}

void  identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The type pointed to by " << p << " is: " << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The type pointed to by " << p << " is: " << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The type pointed to by " << p << " is: " << "C" << std::endl;
}

void  identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The type refered to by " << &p << " is: " << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The type refered to by " << &p << " is: " << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The type refered to by " << &p << " is: " << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
}

int main()
{
    Base* bob = generate();
    std::cout << "bob is: " << bob << std::endl;
    identify(bob);
    identify(*bob);
}
