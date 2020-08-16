//
// Created by itaik on 28/12/2018.
//

#ifndef ASSIGNMENT5_CREATURE_H
#define ASSIGNMENT5_CREATURE_H
#include <stdlib.h>
#include "GameException.h"
using namespace std;

class Creature{
private:
    int attack;
    int defense;
    int cost;
protected:
    void setStrength(int newAttack);
    void setDefense(int newDefense);
    void setCost(int newCost);
public:
    Creature() {attack = 1; defense = 1; cost = 50;};
    virtual ~Creature();
    void details();
    virtual int fight(Creature& other, int amountOfAttackers) = 0;
    virtual int defend(Creature& other, int amountOfDamage) = 0;
    virtual string getType() = 0;
    virtual bool uniqueAbility(Creature& other) = 0;
    int getCost();
    int getDefense();
    int getStrength();
};



#endif //ASSIGNMENT5_CREATURE_H
