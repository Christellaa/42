#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria*   tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    {
        AMateria* originalMateria = new Ice();
        AMateria* clonedMateria   = originalMateria->clone();
        delete originalMateria; // Should not delete the clone
        delete clonedMateria;   // Only the clonedMateria should be deleted here
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    { // Check if Materia is properly freed
        Character* char1 = new Character("Character1");
        AMateria*  ice   = new Ice();
        char1->equip(ice);
        delete char1;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    { // make sure use() method works properly
        Character* char2 = new Character("Character2");
        AMateria*  cure  = new Cure();
        char2->equip(cure);
        Character* target = new Character("Target");
        char2->use(0, *target);
        delete char2;
        delete target;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    { // same type added twice to equip
        Character* char1 = new Character("Character1");
        AMateria*  ice   = new Ice();
        AMateria*  ice2  = new Ice();
        char1->equip(ice);
        char1->equip(ice2);
        delete char1;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    { // full equipped + full unequipped
        Character* char1 = new Character("Character1");
        AMateria*  ice   = new Ice();
        AMateria*  cure  = new Cure();
        AMateria*  ice2  = new Ice();
        AMateria*  cure2 = new Cure();
        AMateria*  cure3 = new Cure();
        AMateria*  cure4 = new Cure();
        AMateria*  cure5 = new Cure();
        AMateria*  cure6 = new Cure();
        AMateria*  cure7 = new Cure();

        char1->equip(ice);
        char1->equip(cure);
        char1->equip(ice2);
        char1->equip(cure2);
        char1->equip(cure3);
        char1->equip(cure4);
        char1->equip(cure5);
        char1->equip(cure6);
        char1->equip(cure7);

        delete char1;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    { // use() method with invalid idx + check equipped and unequipped + deletion of both
        Character* char2 = new Character("Character2");

        char2->equip(new Ice());
        char2->equip(new Cure());
        char2->equip(new Ice());
        char2->equip(new Cure());

        char2->unequip(0);
        std::cout << "Equipped[0]: " << char2->getEquippedMateria(0) << std::endl;
        std::cout << "Equipped[1]: " << char2->getEquippedMateria(1) << std::endl;
        std::cout << "Equipped[2]: " << char2->getEquippedMateria(2) << std::endl;
        char2->unequip(0);

        std::cout << "Equipped[0]: " << char2->getEquippedMateria(0) << std::endl;
        std::cout << "Equipped[1]: " << char2->getEquippedMateria(1) << std::endl;
        std::cout << "Equipped[2]: " << char2->getEquippedMateria(2) << std::endl;

        std::cout << "Unequipped[0]: " << char2->getUnequippedMateria(0) << std::endl;
        std::cout << "Unequipped[1]: " << char2->getUnequippedMateria(1) << std::endl;

        Character* target = new Character("Target");
        char2->use(3, *target);

        delete char2;
        delete target;
    }
}
