//
// Created by itaik on 28/12/2018.
//

#include "Zombie.h"

Zombie::~Zombie() {
    // do nothing here
}

string Zombie::getType() {
    return "Zombie";
}

bool Zombie::uniqueAbility(Creature& other) {
    return (other.getType()=="Archer");
}

int Zombie::fight(Creature& other, int amountOfAttackers){
    int fightStrength = this->Creature::getStrength();
    if(this->uniqueAbility(other)){
        fightStrength = fightStrength*2;
    }
    return fightStrength*amountOfAttackers;
}

int Zombie::defend(Creature& other, int amountOfDamage){
    int killedZombies = amountOfDamage/this->getDefense();
    return killedZombies;
}