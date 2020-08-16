//
// Created by tomer on 30/12/2018.
//

#ifndef ASSIGNMENT5_BLACK_DRAGON_H
#define ASSIGNMENT5_BLACK_DRAGON_H

#include "Creature.h"


class Black_Dragon : public Creature{
public:
    Black_Dragon(){Creature::setStrength(9);Creature::setDefense(10);Creature::setCost(150);};
    ~Black_Dragon();
    string getType();
    bool uniqueAbility(Creature& other);
    int fight(Creature& other, int amountOfAttackers);
    int defend(Creature& other, int amountOfDamage);
};

#endif //ASSIGNMENT5_BLACK_DRAGON_H
