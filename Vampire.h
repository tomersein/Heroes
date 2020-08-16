//
// Created by itaik on 28/12/2018.
//

#ifndef ASSIGNMENT5_VAMPIRE_H
#define ASSIGNMENT5_VAMPIRE_H

#include "Creature.h"

class Vampire : public Creature{
public:
    Vampire(){Creature::setStrength(4);Creature::setDefense(4);Creature::setCost(80);};
    ~Vampire();
    string getType();
    bool uniqueAbility(Creature& other);
    int fight(Creature& other, int amountOfAttackers);
    int defend(Creature& other, int amountOfDamage);
};


#endif //ASSIGNMENT5_VAMPIRE_H
