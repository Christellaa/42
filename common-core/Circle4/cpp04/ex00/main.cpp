#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j    = new Dog();
        const Animal* i    = new Cat();
        std::cout << j->getType() << " will output the dog sound:" << std::endl;
        j->makeSound();
        std::cout << i->getType() << " will output the cat sound:" << std::endl;
        i->makeSound();
        std::cout << meta->getType() << ":" << std::endl;
        meta->makeSound();
        delete (meta);
        delete (j);
        delete (i);
    }

    std::cout << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const Animal*      j    = new Dog();
        const WrongAnimal* i    = new WrongCat();
        std::cout << j->getType() << " will output the dog sound:" << std::endl;
        j->makeSound();
        std::cout << i->getType() << " will output the dog sound:" << std::endl;
        i->makeSound();
        std::cout << meta->getType() << " will output some nonsense:" << std::endl;
        meta->makeSound();
        delete (meta);
        delete (j);
        delete (i);
    }
}
