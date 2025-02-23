#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    //    Animal animal; // not allowed because there's at least one pure virtual method
    Dog dog;
    dog.makeSound();
    dog.getBrain().setIdea(0, "EAT");
    std::cout << "Dog idea[0]: " << dog.getBrain().getIdea(0) << std::endl;
}
