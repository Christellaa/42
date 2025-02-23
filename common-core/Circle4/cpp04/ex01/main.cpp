#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        int     size = 6;
        Animal* animals[size];
        for (int i = 0; i < size / 2; ++i)
            animals[i] = new Dog();
        for (int i = size / 2; i < size; ++i)
            animals[i] = new Cat();
        for (int i = 0; i < size; ++i)
            animals[i]->makeSound();
        for (int i = 0; i < size; ++i)
            delete (animals[i]);
    }
    {
        Dog* dog = new Dog();
        std::cout << "Create ideas EAT and SLEEP for dog" << std::endl;
        dog->getBrain().setIdea(0, "EAT");
        dog->getBrain().setIdea(1, "SLEEP");
        std::cout << "Dog idea[0]: " << dog->getBrain().getIdea(0) << std::endl;
        std::cout << "Dog idea[1]: " << dog->getBrain().getIdea(1) << std::endl;
        std::cout << "Create dog2" << std::endl;
        Dog* dog2 = new Dog(*dog);
        std::cout << "Delete dog" << std::endl;
        delete (dog);
        dog2->makeSound();
        std::cout << "Dog2 idea[0]: " << dog2->getBrain().getIdea(0) << std::endl;
        std::cout << "Dog2 idea[1]: " << dog2->getBrain().getIdea(1) << std::endl;
        delete (dog2);
    }
}
