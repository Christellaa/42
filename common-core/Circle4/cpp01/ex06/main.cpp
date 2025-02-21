#include "Harl.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " <level>" << std::endl;
        std::cout << "Level can be either DEBUG, INFO, WARNING or ERROR" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(av[1]);
}
