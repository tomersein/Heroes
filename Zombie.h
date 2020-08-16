//
// Created by itaik on 28/12/2018.
//

#ifndef ASSIGNMENT5_ZOMBIE_H
#define ASSIGNMENT5_ZOMBIE_H

#include "Creature.h"

class Zombie : public Creature{
public:
    Zombie(){Creature::setStrength(2); Creature::setDefense(5); Creature::setCost(50);};
    ~Zombie();
    string getType();
    bool uniqueAbility(Creature& other);
    int fight(Creature& other, int amountOfAttackers);
    int defend(Creature& other, int amountOfDamage);
};



#endif //ASSIGNMENT5_ZOMBIE_H
