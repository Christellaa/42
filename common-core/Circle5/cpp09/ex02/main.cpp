// use std::list and std::vector
#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>

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

void printBefore(std::list<int>& list)
{
    std::cout << "before: ";
    std::list<int>::iterator it = list.begin();
    bool firstValue = true;
    while (it != list.end())
    {
        if (!firstValue)
            std::cout << " ";
        firstValue = false;
        std::cout << *it;
        ++it;
    }
    std::cout << std::endl;
}

void mergePairs(std::list<int>& list, int &order)
{
    int pairSize = list.size() / order;
    if (pairSize < 2)
        return;
    bool isOdd = pairSize % 2 == 1;
    std::list<int>::iterator begin = list.begin();
    std::list<int>::iterator end = begin;
    std::advance(end, (order * pairSize) - (isOdd * order));
    std::list<int>::iterator it = begin;
    while (it != end)
    {
        std::list<int>::iterator first = it;
        std::advance(first, order - 1);
        std::list<int>::iterator second = it;
        std::advance(second, order * 2 - 1);
        std::cout << "Comparing " << *first << " with " << *second << std::endl;
        if (*first > *second)
        {
            std::cout << "Swapping..." << std::endl;
            for (int i = 0; i < order; ++i)
            {
                std::list<int>::iterator firstElement = it;
                std::advance(firstElement, i);
                std::list<int>::iterator secondElement = it;
                std::advance(secondElement, order + i);
                std::swap(*firstElement, *secondElement);
            }
        }
        std::advance(it, order * 2);
    }
    printBefore(list);
    order *= 2;
    mergePairs(list, order);
}

// use jacobsthal to determine the indices for precessing elements in a pecific order during insertion
int getJacobsthal(int number)
{
    // formula: Jacobsthal(number) = (2^ (number + 1) + (-1) ^number) / 3
    return round((pow(2, number + 1) + pow(-1, number)) / 3);
}

void insertPairs(std::list<int> list, std::list<int> main, std::list<int> pend, int order)
{
    /*
    1. init main and pend containers
    2a. if pend size = 1: sort using binary search (use std::upperbound)
    3b. if pend size > 1: sort using jacobsthal(start with jacobsthal = 3):
    */
}

void fjmiSort(PmergeMe& pmerge)
{
    int order = 1;
    mergePairs(pmerge.getList(), order);
    std::cout << "order after merging: " << order << std::endl;
    order /= 2;
    std::list<int> main; // keep last elem of each pair
    std::list<int> pend; // keep last elem of each pair
    std::list<int> leftover; // no pairs
    insertPairs(pmerge.getList(), main, pend, order);
}

int main(int ac, char** av)
{
    try
    {
        if (ac < 2)
            throw PmergeMe::UsageException();
        PmergeMe pmerge;
        parseSequence(av, pmerge);
        printBefore(pmerge.getList());
        fjmiSort(pmerge);
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
