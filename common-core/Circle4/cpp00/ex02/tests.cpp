// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <algorithm>
#include <functional>
#include <vector>

int main(void)
{
    // dynamic array of class Account named accounts_t, where each element is an Account object
    typedef std::vector<Account::t> accounts_t;
    // dynamic array of type int named ints_t, will be used to hold deposits and withdrawals
    typedef std::vector<int> ints_t;
    // group accounts_t and ints_t to iterate them together like a key-value pair, named acc_int_t
    typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

    // create int array named amounts, will be associated with each account
    int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
    // calculate the size of amounts array in terms of nb of elements
    // - sizeof(amounts) = total size in bytes
    // - sizeof(int) = size of a single int in bytes
    // - sizeof(amounts) / sizeof(int) = nb of elements in the array
    size_t const amounts_size(sizeof(amounts) / sizeof(int));
    // it creates a vector that creates 8 Account objects, each init with a value from amounts array
    // - the 1st arg is a ptr to the beginning of the amounts array
    // - the 2nd arg is a ptr to the last element of the amounts array, determining the range of
    // values used for init
    accounts_t accounts(amounts, amounts + amounts_size);
    // create an iterator to the first element (= account object) of the vector
    accounts_t::iterator acc_begin = accounts.begin();
    // create an iterator to the past the last element (= account object) of the vector
    accounts_t::iterator acc_end = accounts.end();

    int const        d[] = {5, 765, 564, 2, 87, 23, 9, 20};
    size_t const     d_size(sizeof(d) / sizeof(int));
    ints_t           deposits(d, d + d_size);
    ints_t::iterator dep_begin = deposits.begin();
    ints_t::iterator dep_end   = deposits.end();

    int const        w[] = {321, 34, 657, 4, 76, 275, 657, 7654};
    size_t const     w_size(sizeof(w) / sizeof(int));
    ints_t           withdrawals(w, w + w_size);
    ints_t::iterator wit_begin = withdrawals.begin();
    ints_t::iterator wit_end   = withdrawals.end();

    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

    for (acc_int_t it(acc_begin, dep_begin); it.first != acc_end && it.second != dep_end;
         ++(it.first), ++(it.second))
    {
        (*(it.first)).makeDeposit(*(it.second));
    }

    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

    for (acc_int_t it(acc_begin, wit_begin); it.first != acc_end && it.second != wit_end;
         ++(it.first), ++(it.second))
    {
        (*(it.first)).makeWithdrawal(*(it.second));
    }

    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

    return 0;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
