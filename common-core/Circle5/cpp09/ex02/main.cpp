// use std::list and std::vector
#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

void isAPositiveNumber(std::string arg)
{
    // std::cout << "arg in: " << arg << std::endl;
    for (size_t i = 0; i < arg.size(); ++i)
    {
        // std::cout << "arg[i]: [" << arg[i] << "]" << std::endl;
        if (i == 0 && arg[i] == '+')
        {
            if (!isdigit(arg[i + 1]))
                throw PmergeMe::NotANumberException();
        }
        else if (i == 0 && arg[i] == '-' && isdigit(arg[i + 1]))
            throw PmergeMe::NegativeNumberException();
        else if (!isdigit(arg[i]))
            throw PmergeMe::NotANumberException();
    }
}

void isAnInt(std::string arg)
{
    char*  end    = NULL;
    double number = std::strtod(arg.c_str(), &end);
    if (number > std::numeric_limits<int>::max())
        throw PmergeMe::TooLargeNumberException();
}

void parseSequence(char** av)
{
    int i = 1;
    while (av[i])
    {
        // std::cout << "av[i]: [" << av[i] << "]" << std::endl;
        std::stringstream ss(av[i]);
        std::string       arg;
        if (!(ss >> arg))
            throw PmergeMe::UsageException();
        do
        {
            // std::cout << "arg: [" << arg << "]" << std::endl;
            isAPositiveNumber(arg);
            isAnInt(arg);
        } while (ss >> arg);
        i++;
    }
}

void printBefore(char** av)
{
    int  i        = 1;
    bool firstArg = true;
    while (av[i])
    {
        if (!firstArg)
            std::cout << " ";
        firstArg = false;
        std::stringstream ss(av[i]);
        std::string       arg;
        bool              firstValue = true;
        while (ss >> arg)
        {
            if (!firstValue)
                std::cout << " ";
            firstValue = false;
            std::cout << arg;
        }
        i++;
    }
    std::cout << std::endl;
}

int main(int ac, char** av)
{
    try
    {
        if (ac < 2)
            throw PmergeMe::UsageException();
        parseSequence(av);
        printBefore(av);
        // sort();
        // printAfter();
        // printUsageTime();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

/*
clock:
- starts before parsing
- ends after sorting

parsing:
+ argument is a positive integer sequence (duplicates are managed as we want)
- accept only int (careful of intmin and intmax)
- one int per av[i]
- accept only positive

execution:
- follow the ford-johnson algo
- only one number in the sequence -> do nothing because it's already ordered

what should be printed:
- 1st line = explicit text followed by unsorted sequence
- 2nd line = explicit text followed by sorted sequence
- 3rd line = explicit text indicating the time used by first container
- 4th line = explicit text indicating the time used by second container
*/
