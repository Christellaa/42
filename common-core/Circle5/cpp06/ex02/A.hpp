#ifndef _A_HPP_
#define _A_HPP_

#include "Base.hpp"

class A : public Base
{
    Base* generate(void);
    void  identify(Base* p);
    void  identify(Base& p);
};

#endif
