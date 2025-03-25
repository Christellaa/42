#include "MutantStack.hpp"

template <class T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <class T> MutantStack<T>::MutantStack(MutantStack const& copy) : std::stack<T>(copy) {}

template <class T> MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& rhs)
{
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return *this;
}

template <class T> MutantStack<T>::~MutantStack() {}

template <class T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <class T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <class T> typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return this->c.begin();
}

template <class T> typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return this->c.end();
}

template <class T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <class T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}
