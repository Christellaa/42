#include "PmergeMe.hpp"
#include "fjmiSort.hpp"
#include "fjmiSort.tpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

void isAPositiveNumber(std::string arg)
{
    for (size_t i = 0; i < arg.size(); ++i)
    {
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

void parseSequence(char** av, PmergeMe& pmerge)
{
    int i = 1;
    while (av[i])
    {
        std::stringstream ss(av[i]);
        std::string       arg;
        if (!(ss >> arg))
            throw PmergeMe::UsageException();
        do
        {
            isAPositiveNumber(arg);
            isAnInt(arg);
            pmerge.getList().push_back(atoi(arg.c_str()));
            pmerge.getVector().push_back(atoi(arg.c_str()));
        } while (ss >> arg);
        i++;
    }
}

void printElapsedTime(clock_t start, clock_t end, std::string containerName, size_t size)
{
    double durationList = double(end - start) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << size
              << " with " << containerName << ": " << durationList << " us" << std::endl;
}

int main(int ac, char** av)
{
    try
    {
        if (ac < 2)
            throw PmergeMe::UsageException();
        PmergeMe pmerge;
        parseSequence(av, pmerge);
        std::cout << "Before: ";
        printList(pmerge.getList());
        clock_t startList = std::clock();
        fjmiSort(pmerge.getList());
        clock_t endList     = std::clock();
        clock_t startVector = std::clock();
        fjmiSort(pmerge.getVector());
        clock_t endVector = std::clock();
        std::cout << "After: ";
        printList(pmerge.getList());
        printElapsedTime(startList, endList, "std::list", pmerge.getList().size());
        printElapsedTime(startVector, endVector, "std::vector", pmerge.getVector().size());
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
