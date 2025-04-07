#ifndef FJMISORT_H
#define FJMISORT_H

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

template <typename Container> void printList(Container& list);

template <typename Container> void mergePairs(Container& list, int& order);

template <typename Container>
void moveInLists(Container list, Container& main, Container& pend, Container& leftover);

int getJacobsthal(int number);

template <typename Container> void insertElementIntoMain(Container& main, int element);

template <typename Container>
void insertPendAndLeftoverIntoMain(Container& main, Container& pend, Container& leftover);

template <typename Container> void fjmiSort(Container& list);

#endif
