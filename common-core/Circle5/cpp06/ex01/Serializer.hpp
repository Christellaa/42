#ifndef _SERIALIZER_HPP_
#define _SERIALIZER_HPP_

#include "data.h"
#include <stdint.h>

class Serializer
{
  public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);

  private:
    Serializer();
    Serializer(const Serializer& copy);
    ~Serializer();

    Serializer& operator=(const Serializer& rhs);
};

#endif

/*
uintptr_t:
- unsigned int where any valid "void* value" can be converted to this type and back
- can store values from 0 to INTPTR_MAX
+ UINTPTR_WIDTH = width in bits of uintptr_t
+ UINTPTR_MAX = max value uintptr_t can hold
*/
