#include "Fixed.hpp"

int main()
{
    Fixed       a(2);
    Fixed const b(Fixed(5.05f) * Fixed(2)); // b = 5.05 * 2

    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << std::endl; // Should print 0 (default value)
    std::cout << "b: " << b << std::endl; // Should print 10.1016 (5.05 * 2)

    // Increment operators (both pre and post)
    std::cout << "\nIncrement operators:" << std::endl;
    std::cout << "Pre-increment a: " << ++a << std::endl; // Should increment a first, then print
    std::cout << "a after pre-increment: " << a << std::endl;  // Print a after increment
    std::cout << "Post-increment a: " << a++ << std::endl;     // Should print a, then increment
    std::cout << "a after post-increment: " << a << std::endl; // Print a after increment

    // Decrement operators (both pre and post)
    std::cout << "\nDecrement operators:" << std::endl;
    std::cout << "Pre-decrement a: " << --a << std::endl; // Should decrement a first, then print
    std::cout << "a after pre-decrement: " << a << std::endl;  // Print a after decrement
    std::cout << "Post-decrement a: " << a-- << std::endl;     // Should print a, then decrement
    std::cout << "a after post-decrement: " << a << std::endl; // Print a after decrement

    // Comparison operators
    std::cout << "\nComparison operators:" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl; // Should print 0 (false) if a != b
    std::cout << "a != b: " << (a != b) << std::endl; // Should print 1 (true) if a != b
    std::cout << "a < b: " << (a < b) << std::endl;   // Should print 1 (true) if a < b
    std::cout << "a <= b: " << (a <= b) << std::endl; // Should print 1 (true) if a <= b
    std::cout << "a > b: " << (a > b) << std::endl;   // Should print 0 (false) if a > b
    std::cout << "a >= b: " << (a >= b) << std::endl; // Should print 0 (false) if a >= b

    // Arithmetic operators
    std::cout << "\nArithmetic operators:" << std::endl;
    std::cout << "a + b: " << a + b << std::endl; // Should print the result of a + b
    std::cout << "a - b: " << a - b << std::endl; // Should print the result of a - b
    std::cout << "a * b: " << a * b << std::endl; // Should print the result of a * b
    std::cout << "a / b: " << a / b << std::endl; // Should print the result of a / b

    // Max function
    std::cout << "\nMax function:" << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
    // Should print the largest value between a and b

    // Min function
    std::cout << "\nMin function:" << std::endl;
    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    // Should print the smallest value between a and b
}
