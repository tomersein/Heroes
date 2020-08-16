//
// Created by itaik on 28/12/2018.
//

#include "Archer.h"

Archer::~Archer(){
    // do nothing here, solve later
}

string Archer::getType() {
    return "Archer";
}

bool Archer::uniqueAbility(Creature &other) {
    return(other.getType()=="Black_Dragon");
}

int Archer::fight(Creature& other, int amountOfAttackers){
    int fightStrength = this->Creature::getStrength();
    if(uniqueAbility(other))
        fightStrength = fightStrength + (int)(fightStrength*0.2);
    return fightStrength*amountOfAttackers;
}

int Archer::defend(Creature& other, int amountOfDamage){
    int killedArchers = amountOfDamage/this->getDefense();
    return killedArchers;
}