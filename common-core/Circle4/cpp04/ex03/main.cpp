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
    {
        AMateria* originalMateria = new Ice();
        AMateria* clonedMateria   = originalMateria->clone();
        delete originalMateria; // Should not delete the clone
        delete clonedMateria;   // Only the clonedMateria should be deleted here
    }
    {
        Character* char1 = new Character("Character1");
        AMateria*  ice   = new Ice();
        char1->equip(ice);
        delete char1; // Check if Materia is properly freed
    }
    {
        Character* char2 = new Character("Character2");
        AMateria*  cure  = new Cure();
        char2->equip(cure);
        Character* target = new Character("Target");
        char2->use(0, *target); // Ensure the use() method functions properly
        delete char2;
        delete target;
    }
    // { // not freed somewhere
    //     Character* char1   = new Character("Character1");
    //     AMateria*  ice     = new Ice();
    //     AMateria*  cure    = new Cure();
    //     AMateria*  cure2   = new Ice();
    //     AMateria*  thunder = new Cure();

    //     char1->equip(ice);     // Equip Ice
    //     char1->equip(cure);    // Equip Cure
    //     char1->equip(cure2);   // Equip Fire
    //     char1->equip(thunder); // Equip Thunder

    //     AMateria* ice2 = new Ice(); // Try to equip one more Materia (should fail)
    //     char1->equip(ice2);         // Expected failure

    //     delete char1; // Check if all 4 equipped Materia are properly freed
    // }
    // { // not freed somewhere
    //     Character* char2 = new Character("Character2");

    //     // Equip 4 Materia objects (inventory will be full)
    //     char2->equip(new Ice());
    //     char2->equip(new Cure());
    //     char2->equip(new Ice());
    //     char2->equip(new Cure());

    //     // Now the inventory is full, try to equip more
    //     char2->equip(new Ice()); // Should go to unequippedMateria

    //     // Equip a couple more Materia and check the unequippedMateria array
    //     char2->equip(new Cure());
    //     char2->equip(new Ice()); // Should continue adding to unequippedMateria

    //     // Use unequipped Materia on a target
    //     Character* target = new Character("Target");
    //     char2->use(4, *target); // Use 1st unequipped Materia (Wind)
    //     char2->use(5, *target); // Use 2nd unequipped Materia (Water)

    //     delete char2; // Check if both equipped and unequipped Materia are deleted properly
    //     delete target;
    // }
    // { // not freed somewhere
    //     Character* char3 = new Character("Character3");

    //     // Equip 4 Materia objects (maximum capacity reached)
    //     char3->equip(new Ice());
    //     char3->equip(new Cure());
    //     char3->equip(new Ice());
    //     char3->equip(new Cure());

    //     // Try to equip more Materia beyond the limit (should be rejected or handled)
    //     char3->equip(new Ice());  // Should not be added
    //     char3->equip(new Cure()); // Should not be added

    //     // Ensure the memory for the equipped Materia is freed properly when the character is
    //     // deleted
    //     delete char3; // Check with Valgrind to ensure no memory leaks
    // }g
}
