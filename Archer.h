//
// Created by itaik on 28/12/2018.
//

#ifndef ASSIGNMENT5_ARCHER_H
#define ASSIGNMENT5_ARCHER_H

#include "Creature.h"

class Archer : public Creature{
public:
    Archer(){Creature::setStrength(5); Creature::setDefense(4); Creature::setCost(90);}
    ~Archer();
    string getType();
    bool uniqueAbility(Creature& other);
    int fight(Creature& other, int amountOfAttackers);
    int defend(Creature& other, int amountOfDamage);
};

#endif //ASSIGNMENT5_ARCHER_H
