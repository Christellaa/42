#ifndef _BRAIN_HPP_
#define _BRAIN_HPP_

#include <iostream>

class Brain
{
  public:
    Brain();
    Brain(const Brain& copy);
    virtual ~Brain();

    Brain&             operator=(const Brain& rhs);
    void               setIdea(int idx, std::string idea);
    std::string const& getIdea(int idx) const;

  private:
    std::string _ideas[100];
};

#endif
