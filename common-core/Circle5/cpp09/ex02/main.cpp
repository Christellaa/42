// use std::list and std::vector
#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
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

void printList(List& list)
{
    Iterator it         = list.begin();
    bool     firstValue = true;
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

void mergePairs(List& list, int& order)
{
    int pairSize = list.size() / order;
    if (pairSize < 2)
        return;
    bool     isOdd = pairSize % 2 == 1;
    Iterator it    = list.begin();
    Iterator end   = it;
    std::advance(end, (order * pairSize) - (isOdd * order));
    while (it != end)
    {
        Iterator first = it;
        std::advance(first, order - 1);
        Iterator second = it;
        std::advance(second, order * 2 - 1);
        // std::cout << "Comparing " << *first << " with " << *second << std::endl;
        if (*first > *second)
        {
            // std::cout << "Swapping..." << std::endl;
            for (int i = 0; i < order; ++i)
            {
                Iterator firstElement = it;
                std::advance(firstElement, i);
                Iterator secondElement = it;
                std::advance(secondElement, order + i);
                std::swap(*firstElement, *secondElement);
            }
        }
        std::advance(it, order * 2);
    }
    // std::cout << "List: ";
    // printList(list);
    order *= 2;
    mergePairs(list, order);
}

void moveInLists(List list, List& main, List& pend, List& leftover)
{
    if (list.size() % 2 == 1)
    {
        leftover.push_back(list.back());
        list.pop_back();
    }
    for (Iterator first = list.begin(); first != list.end();)
    {
        Iterator second = first;
        std::advance(second, 1);
        main.push_back(*second);
        pend.push_back(*first);
        std::advance(first, 2);
    }
}

// use jacobsthal to determine the indices for processing elements in a pecific order during
// insertion
int getJacobsthal(int number)
{
    // formula: Jacobsthal(number) = (2^ (number + 1) + (-1) ^number) / 3
    return round((pow(2, number + 1) + pow(-1, number)) / 3);
}

void insertElementIntoMain(List& main, int element)
{
    Iterator it = std::upper_bound(main.begin(), main.end(), element);
    main.insert(it, element);
    // std::cout << "Element to insert: " << element << std::endl;
    // std::cout << "Element after which it's inserted: " << *it << std::endl;
    // printList(main);
}

void insertPendAndLeftoverIntoMain(List& main, List& pend, List& leftover)
{
    if (pend.empty())
        return;
    std::list<bool> inserted(pend.size(), false);
    // INSERT PEND
    // insert first element
    insertElementIntoMain(main, pend.front());
    *inserted.begin() = true;
    // insert elements following jacobsthal indices
    for (int i = 1;; ++i)
    {
        size_t jacobsthal = getJacobsthal(i);
        if (jacobsthal >= pend.size())
            break;
        std::list<bool>::iterator it = inserted.begin();
        std::advance(it, jacobsthal);
        if (*it == false)
        {
            Iterator element = pend.begin();
            std::advance(element, jacobsthal);
            insertElementIntoMain(main, *element);
            *it = true;
        }
    }
    // insert remaining elements
    for (size_t i = 0; i < pend.size(); ++i)
    {
        std::list<bool>::iterator it = inserted.begin();
        std::advance(it, i);
        if (*it == false)
        {
            Iterator element = pend.begin();
            std::advance(element, i);
            insertElementIntoMain(main, *element);
        }
    }
    // INSERT LEFTOVER
    if (!leftover.empty())
        insertElementIntoMain(main, leftover.front());
}

void fjmiSort(List& list)
{
    if (list.size() < 2)
        return;
    int order = 1;
    mergePairs(list, order);
    // std::cout << "order after merging: " << order << std::endl;
    order /= 2;
    List main;
    List pend;
    List leftover;
    moveInLists(list, main, pend, leftover);
    // std::cout << "main: ";
    // printList(main);
    // std::cout << "pend: ";
    // printList(pend);
    // std::cout << "leftover: ";
    // printList(leftover);
    fjmiSort(main);
    insertPendAndLeftoverIntoMain(main, pend, leftover);
    list = main;
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
        fjmiSort(pmerge.getList());
        std::cout << "After: ";
        printList(pmerge.getList());
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
