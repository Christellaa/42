#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("clap1");
    ClapTrap clap2("clap2");
    ClapTrap clap3("clap3");

    clap.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap3.attack("clap2");
    clap2.takeDamage(2);
    clap2.takeDamage(2);
    clap2.takeDamage(2);
    clap2.takeDamage(2);
    clap2.beRepaired(4);
    clap2.beRepaired(7);
    clap2.attack("clap");
    clap.takeDamage(3);
    clap.beRepaired(1);
    clap.takeDamage(3);
    clap.takeDamage(3);
    clap.takeDamage(3);
    clap.takeDamage(3);
    clap.beRepaired(1);
    clap.attack("clap2");
    clap2.beRepaired(7);
    clap2.beRepaired(7);
    clap2.beRepaired(7);
    clap2.beRepaired(7);
    clap2.beRepaired(7);
    clap2.beRepaired(7);
    clap2.beRepaired(7);
    clap2.beRepaired(7);
}
