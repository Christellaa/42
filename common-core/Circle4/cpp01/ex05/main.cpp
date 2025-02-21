#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("info");
    harl.complain("debug");
    harl.complain("warning");
    harl.complain("error");
    Harl harl2;
    harl2.complain("debug");
    harl2.complain("");
    Harl harl3;
    harl3.complain("I have no idea");
    harl3.complain("error");
    harl3.complain("I still have no idea");
    Harl harl4;
    harl4.complain("info");
}
