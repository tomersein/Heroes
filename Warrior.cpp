//
// Created by itaik on 28/12/2018.
//

#include "Warrior.h"

Warrior::Warrior() {
    this->Hero::setGold(750);
    this->Hero::setName("warrior");
    type = "Warrior";
}

Warrior::~Warrior(){

}

Warrior::Warrior(string newName){
    if(!this->Hero::setName(newName)){
        throw CorruptUserException(newName);
    }
    this->Hero::setGold(750);
    type = "Warrior";
}

Warrior::Warrior(string warName, string warType, string warGold, string warDrag, string warWiz, string warArch, string warVamp, string warZomb):
Hero(warName, warType, warGold, warDrag, warWiz, warArch, warVamp, warZomb) {

};

void Warrior::specialAbility(Hero& other) {
    this->Hero::setGold(50);
}
