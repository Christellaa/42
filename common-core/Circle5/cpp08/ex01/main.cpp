#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    Span sp = Span(5);
    std::cout << "------------" << std::endl;
    std::cout << "All working:" << std::endl;
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.showNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Not enough numbers for shortest/longest span:" << std::endl;
    Span sp2(3);
    try
    {
        sp2.addNumber(8);
        sp2.showNumbers();
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Max number exceeded:" << std::endl;
    Span sp3(2);
    try
    {
        sp3.addNumber(5);
        sp3.addNumber(4);
        sp3.addNumber(2);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Shortest/Longest span with same numbers" << std::endl;
    Span sp4(3);
    try
    {
        sp4.addNumber(1);
        sp4.addNumber(1);
        sp4.addNumber(1);
        sp4.showNumbers();
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Negative numbers in Span to be used to get shortest/longest span:" << std::endl;
    Span sp5(10);
    try
    {
        sp5.addNumber(-1);
        sp5.addNumber(-10);
        sp5.addNumber(-6);
        sp5.showNumbers();
        std::cout << "Shortest span:" << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Test with 10000 numbers and a single call to add numbers:" << std::endl;
    Span             sp6(10000);
    std::vector<int> v;
    std::srand(std::time(0));
    for (int i = 0; i < 10000; ++i)
    {
        int number = rand();
        v.push_back(number);
    }
    try
    {
        sp6.addNumbers(v.begin(), v.end());
        // sp6.showNumbers();
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
