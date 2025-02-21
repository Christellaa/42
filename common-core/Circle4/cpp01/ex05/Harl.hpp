#ifndef _HARL_HPP_
#define _HARL_HPP_

#include "Harl.h"

class Harl
{
  public:
    void complain(std::string level);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

typedef void (Harl::*becomeAnnoying)();

#endif
