#ifndef CONVERTS_H
#define CONVERTS_H

#include <cstdlib>
#include <iostream>

void invalidLiteral(std::string& literal);
void convertSpecial(std::string& literal);
void convertChar(std::string& literal);
void convertInt(std::string& literal);
void convertFloat(std::string& literal);
void convertDouble(std::string& literal);

#endif
