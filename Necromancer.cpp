//
// Created by tomer on 30/12/2018.
//

#include "Necromancer.h"

Necromancer::Necromancer() {
    this->Hero::setGold(750);
    this->Hero::setName("necromancer");
    type = "Necromancer";
}

Necromancer::~Necromancer(){

}

Necromancer::Necromancer(string newName){
    if(!this->Hero::setName(newName)){
        throw CorruptUserException(newName);
    }
    this->Hero::setGold(750);
    type = "Necromancer";
}

Necromancer::Necromancer(string necName, string necType, string necGold, string necDrag, string necWiz, string necArch,
                         string necVamp, string necZomb): Hero(necName, necType, necGold, necDrag, necWiz, necArch, necVamp, necZomb) {

};

void Necromancer::specialAbility(Hero& other) {
    this->army[ZOMBIE]++;
}
