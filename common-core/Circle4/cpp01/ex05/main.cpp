#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("ERROR");
    Harl harl2;
    harl2.complain("DEBUG");
    harl2.complain("");
    Harl harl3;
    harl3.complain("I have no idea");
    harl3.complain("ERROR");
    harl3.complain("I still have no idea");
    Harl harl4;
    harl4.complain("INFO");
}
