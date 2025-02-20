#include "Harl.hpp"

// function ptr to a member function = ptr that can refer to a member function
//    if a specific class
// that kinda function is associated with an instance of a class, which means
//    it has an implicit THIS ptr that points to the object invoking the object
// written like this: return_type (ClassName::*ptrName)(argTypes) = &ClassName::memberFunction;
//    return_type = return type of the member function
//    className = name of the class to which the member function belongs
//    *ptrName = name of the function ptr variable
//    argTypes = types of the args accepted by the member function
//    &ClassName::memberFunction = address of the member function being assigned to the function ptr

void Harl::complain(std::string level)
{
	;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup \\
	burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \\
	enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for \\
	years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
