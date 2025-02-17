#include "Zombie.hpp"

int main()
{
    Zombie* horde1 = zombieHorde(12, "Bob");
    for (int i = 0; i < 4; ++i)
        horde1[i].announce();
    delete[] horde1;
}
