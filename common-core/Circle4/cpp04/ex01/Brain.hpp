#ifndef _BRAIN_H_
#define _BRAIN_H_

#include <iostream>

class Brain
{
  public:
    Brain();
    Brain(const Brain& copy);
    virtual ~Brain();

    Brain& operator=(const Brain& rhs);

  private:
    std::string ideas[100];
};

#endif
