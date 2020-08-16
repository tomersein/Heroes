//
// Created by tomer on 30/12/2018.
//

#include "Wizard.h"


Wizard::~Wizard() {
    // do nothing here
}

string Wizard::getType() {
    return "Wizard";
}

bool Wizard::uniqueAbility(Creature &other) {
    return (other.getType() == "Black_Dragon");
}

int Wizard::fight(Creature& other, int amountOfAttackers) {
    return this->Creature::getStrength()*amountOfAttackers;
}

int Wizard::defend(Creature& other, int amountOfDamage){
    int defensePower = this->getDefense();
    if(this->uniqueAbility(other))
        defensePower = defensePower*2;
    int killedWizards = amountOfDamage/defensePower;
    return killedWizards;
}