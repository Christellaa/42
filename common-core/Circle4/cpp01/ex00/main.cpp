#include "Zombie.hpp"

int main()
{
    Zombie* zombie1 = newZombie("Foo");
    Zombie* zombie2 = newZombie("Foo2");
    Zombie* zombie3 = newZombie("Foo3");
    zombie1->announce();
    zombie2->announce();
    zombie3->announce();
    randomChump("Bar");
    randomChump("Bar2");
    randomChump("Bar3");
    delete (zombie1);
    delete (zombie2);
    delete (zombie3);
}
