//
// Created by itaik on 28/12/2018.
//

#include "Creature.h"

void Creature::details() {
    cout << "Attack level: " << attack << ", Defense level: " << defense << "\n";
}

void Creature::setCost(int newCost) {
    if(newCost>=50 && newCost <=200)
        cost = newCost;
    else{
        cout << "Could not update cost, illegal price was given.\n";
        return;
    }
}

void Creature::setDefense(int newDefense) {
    if(newDefense<=10 && newDefense>=1)
        defense = newDefense;
    else{
        cout << "Could not update defense, illegal parameter was given.\n";
        return;
    }
}

void Creature::setStrength(int newAttack) {
    if(newAttack<=10 && newAttack>=1)
        attack = newAttack;
    else{
        cout << "Could not update strengh, illegal parameter was given.\n";
        return;
    }
}

int Creature::getCost() {
    return cost;
}

int Creature::getStrength() {
    return attack;
}

int Creature::getDefense() {
    return defense;
}

Creature::~Creature() {
    //do nothing here
}