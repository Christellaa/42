#include <iostream>
#include <string>

int main()
{
    std::string  sentence  = "HI THIS IS BRAIN";
    std::string* stringPTR = &sentence;
    std::string& stringREF = sentence;

    std::cout << "Memory address of sentence: " << &sentence << std::endl;
    std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

    std::cout << "Value of sentence: " << sentence << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
