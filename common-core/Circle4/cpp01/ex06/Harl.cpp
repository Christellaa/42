#include "Harl.hpp"

void Harl::printComplains(int lvl)
{
    switch (lvl)
    {
    case 0:
        debug();
        // fall through
    case 1:
        info();
        // fall through
    case 2:
        warning();
        // fall through
    case 3:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}

void Harl::complain(std::string level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int               lvl;
    for (lvl = 0; lvl < 4; ++lvl)
    {
        if (level == levels[lvl])
            break;
    }
    printComplains(lvl);
}

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup "
                 "burger. I really do!"
              << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough "
                 "bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years "
                 "whereas you started working here since last month."
              << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
