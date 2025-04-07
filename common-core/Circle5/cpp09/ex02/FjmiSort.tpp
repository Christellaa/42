#include "FjmiSort.hpp"

template <typename Container> void printList(Container& list)
{
    typename Container::iterator it         = list.begin();
    bool                         firstValue = true;
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

template <typename Container> void mergePairs(Container& list, int& order)
{
    int pairSize = list.size() / order;
    if (pairSize < 2)
        return;
    bool                         isOdd = pairSize % 2 == 1;
    typename Container::iterator it    = list.begin();
    typename Container::iterator end   = it;
    std::advance(end, (order * pairSize) - (isOdd * order));
    while (it != end)
    {
        typename Container::iterator first = it;
        std::advance(first, order - 1);
        typename Container::iterator second = it;
        std::advance(second, order * 2 - 1);
        if (*first > *second)
        {
            for (int i = 0; i < order; ++i)
            {
                typename Container::iterator firstElement = it;
                std::advance(firstElement, i);
                typename Container::iterator secondElement = it;
                std::advance(secondElement, order + i);
                std::swap(*firstElement, *secondElement);
            }
        }
        std::advance(it, order * 2);
    }
    order *= 2;
    mergePairs(list, order);
}

template <typename Container>
void moveInLists(Container list, Container& main, Container& pend, Container& leftover)
{
    if (list.size() % 2 == 1)
    {
        leftover.push_back(list.back());
        list.pop_back();
    }
    for (typename Container::iterator first = list.begin(); first != list.end();)
    {
        typename Container::iterator second = first;
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

template <typename Container> void insertElementIntoMain(Container& main, int element)
{
    typename Container::iterator it = std::upper_bound(main.begin(), main.end(), element);
    main.insert(it, element);
}

template <typename Container>
void insertPendAndLeftoverIntoMain(Container& main, Container& pend, Container& leftover)
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
            typename Container::iterator element = pend.begin();
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
            typename Container::iterator element = pend.begin();
            std::advance(element, i);
            insertElementIntoMain(main, *element);
        }
    }
    // INSERT LEFTOVER
    if (!leftover.empty())
        insertElementIntoMain(main, leftover.front());
}

template <typename Container> void fjmiSort(Container& list)
{
    if (list.size() < 2)
        return;
    int order = 1;
    mergePairs(list, order);
    order /= 2;
    Container main;
    Container pend;
    Container leftover;
    moveInLists(list, main, pend, leftover);
    fjmiSort(main);
    insertPendAndLeftoverIntoMain(main, pend, leftover);
    list = main;
}
