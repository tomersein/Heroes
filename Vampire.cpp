//
// Created by itaik on 28/12/2018.
//

#include "Vampire.h"

Vampire::~Vampire() {
    // do nothing here
}

string Vampire::getType() {
    return "Vampire";
}

bool Vampire::uniqueAbility(Creature &other) {
    return false; // no unique ability for vampires
}

int Vampire::fight(Creature &other, int amountOfAttackers) {
    int fightStrength = this->Creature::getStrength();
    return fightStrength*amountOfAttackers;
}

int Vampire::defend(Creature& other, int amountOfDamage){
    int killedVampires = amountOfDamage/this->getDefense();
    return killedVampires;
}