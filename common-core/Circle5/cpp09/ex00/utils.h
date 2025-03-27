#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>

bool dataExist();
bool isSpaceOrPipe(char c);
bool isLeapYear(int year);
bool isIntOrFloat(std::string value);
float getValue(std::string line);

#endif
