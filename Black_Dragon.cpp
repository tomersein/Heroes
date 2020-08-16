//
// Created by tomer on 30/12/2018.
//

#include "Black_Dragon.h"

Black_Dragon::~Black_Dragon() {
    // do nothing here
}

string Black_Dragon::getType() {
    return "Black_Dragon";
}

bool Black_Dragon::uniqueAbility(Creature &other) {
    return false; // no unique ability for Black Dragon
}

int Black_Dragon::fight(Creature &other, int amountOfAttackers) {
    return this->Creature::getStrength()*amountOfAttackers;
}

int Black_Dragon::defend(Creature& other, int amountOfDamage){
    int killedDragons = amountOfDamage/this->getDefense();
    return killedDragons;
}