#include "easyfind.hpp"

const char* ContainerTypeException::what() const throw()
{
    return ("Container type must be int");
}

const char* OccurenceNotFoundException::what() const throw()
{
    return ("Occurence not found");
}
