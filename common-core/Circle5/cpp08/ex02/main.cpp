#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "Testing MutantStack with int:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        std::cout << "First element: " << mstack.top() << std::endl;
        mstack.push(17);
        std::cout << "Second element: " << mstack.top() << std::endl;
        std::cout << "Pop top from stack" << std::endl;
        mstack.pop();
        std::cout << "Stack size: " << mstack.size() << std::endl;
        mstack.push(3);
        std::cout << "Second element: " << mstack.top() << std::endl;
        mstack.push(5);
        std::cout << "Third element: " << mstack.top() << std::endl;
        mstack.push(737);
        std::cout << "Fourth element: " << mstack.top() << std::endl;
        mstack.push(0);
        std::cout << "Fifth element: " << mstack.top() << std::endl;
        MutantStack<int>::iterator it  = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        std::cout << "Begin: " << *it << std::endl;
        ++it;
        std::cout << "Begin after incrementing: " << *it << std::endl;
        --it;
        std::cout << "Begin after decrementing: " << *it << std::endl;
        std::cout << "Stack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "------------------------" << std::endl;
    std::cout << "std::list gives the same results:" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        std::cout << "First element: " << lst.back() << std::endl;
        lst.push_back(17);
        std::cout << "Second element: " << lst.back() << std::endl;
        std::cout << "Pop back from stack" << std::endl;
        lst.pop_back();
        std::cout << "Stack size: " << lst.size() << std::endl;
        lst.push_back(3);
        std::cout << "Second element: " << lst.back() << std::endl;
        lst.push_back(5);
        std::cout << "Third element: " << lst.back() << std::endl;
        lst.push_back(737);
        std::cout << "Fourth element: " << lst.back() << std::endl;
        lst.push_back(0);
        std::cout << "Fifth element: " << lst.back() << std::endl;
        std::list<int>::iterator it  = lst.begin();
        std::list<int>::iterator ite = lst.end();
        std::cout << "Begin: " << *it << std::endl;
        ++it;
        std::cout << "Begin after incrementing: " << *it << std::endl;
        --it;
        std::cout << "Begin after decrementing: " << *it << std::endl;
        std::cout << "Stack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> slst(lst);
    }

    std::cout << "------------------------" << std::endl;
    std::cout << "Testing MutantStack with string:" << std::endl;
    {
        MutantStack<std::string> mstack;
        mstack.push("hello");
        mstack.push("goodbye");
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.push("no idea");
        mstack.push("how do you do?");
        std::cout << "Stack: " << std::endl;
        MutantStack<std::string>::iterator it  = mstack.begin();
        MutantStack<std::string>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "------------------------" << std::endl;
    std::cout << "Testing MutantStack with float:" << std::endl;
    {
        MutantStack<float> f;
        f.push(0.5412f);
        f.push(5631.2f);
        f.push(875.0f);
        f.push(513);
        f.push(5631.2f);
        std::cout << "Top: " << f.top() << std::endl;
        f.pop();
        std::cout << "Top: " << f.top() << std::endl;
        std::cout << "Stack:" << std::endl;
        MutantStack<float>::iterator it  = f.begin();
        MutantStack<float>::iterator ite = f.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "------------------------" << std::endl;
    std::cout << "Testing empty stack:" << std::endl;
    {
        MutantStack<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;
        empty.push(3);
        std::cout << "Top: " << empty.top() << std::endl;
        empty.pop();
        std::cout << "Size: " << empty.size() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    std::cout << "Testing large numbers in stack:" << std::endl;
    {
        MutantStack<long long> ll;
        ll.push(9223372036854775807LL);  // long long max value
        ll.push(-9223372036854775807LL); // long long min value
        std::cout << "Top: " << ll.top() << std::endl;
        MutantStack<long long>::iterator it  = ll.begin();
        MutantStack<long long>::iterator ite = ll.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "------------------------" << std::endl;
    std::cout << "Testing iterator, const iterator and reverse iterator:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(2);
        mstack.push(-15);
        mstack.push(1254);
        mstack.push(685);
        mstack.push(-56527);
        std::cout << "Iterator:" << std::endl;
        MutantStack<int>::iterator it  = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "Const iterator:" << std::endl;
        MutantStack<int>::const_iterator cit  = mstack.begin();
        MutantStack<int>::const_iterator cite = mstack.end();
        while (cit != cite)
        {
            std::cout << *cit << std::endl;
            ++cit;
        }
        std::cout << "Reverse iterator:" << std::endl;
        MutantStack<int>::reverse_iterator rit  = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }
}
