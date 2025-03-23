#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_

#include <deque>
#include <stack>

template <class T> class MutantStack : public std::stack<T>
{
  public:
    typedef typename std::stack<T>::container_type    container_type;
    typedef typename container_type::iterator         iterator;
    typedef typename container_type::const_iterator   const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;

    iterator begin();
    iterator end();

    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
};

#endif

/*
+ stack is not iterable (= doesn't use iterators) but it's an adapter (= wrapper around another
container)
+ it uses another container (default = deque) which does have iterators
+ the underlying container is name 'c' and is protected
+ stack methods:
- push
- pop
- top
- empty
- size
*/
