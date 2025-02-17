#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    try
    {
        return new Zombie(name);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed: not enough memory available." << std::endl;
        std::cerr << "System message: " << e.what() << std::endl;
        return NULL;
    }
}
