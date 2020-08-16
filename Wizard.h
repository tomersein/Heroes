//
// Created by tomer on 30/12/2018.
//

#ifndef ASSIGNMENT5_WIZARD_H
#define ASSIGNMENT5_WIZARD_H

#include "Creature.h"


class Wizard : public Creature{
public:
    Wizard(){Creature::setStrength(8);Creature::setDefense(2);Creature::setCost(150);};
    ~Wizard();
    string getType();
    bool uniqueAbility(Creature& other);
    int fight(Creature& other, int amountOfAttackers);
    int defend(Creature& other, int amountOfDamage);
};

#endif //ASSIGNMENT5_WIZARD_H
