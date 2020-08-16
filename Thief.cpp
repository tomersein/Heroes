//
// Created by tomer on 30/12/2018.
//

#include "Thief.h"


Thief::Thief(){
    this->Hero::setGold(750);
    this->Hero::setName("thief");
    type = "Thief";
}

Thief::~Thief(){

}

Thief::Thief(string newName){
    if(!this->Hero::setName(newName)){
        throw CorruptUserException(newName);
    }
    this->Hero::setGold(750);
    type = "Thief";
}

Thief::Thief(string thiName, string thiType, string thiGold, string thiDrag, string thiWiz, string thiArch,
             string thiVamp, string thiZomb): Hero(thiName, thiType, thiGold, thiDrag, thiWiz, thiArch, thiVamp, thiZomb) {

};

void Thief::specialAbility(Hero& other){
    if(other.getGold()<70) {
        if(other.getGold()+this->getGold()>2500){
            int amount = (2500-(other.getGold()+this->getGold()))*(-1);
            this->setGold(amount);
            other.setGold(amount*(-1));
        }
        else{
            int amount = other.getGold();
            this->setGold(amount);
            other.setGold(other.getGold()*(-1));
        }
    }
    else{
        if(other.getGold()+this->getGold()>2500){
            int amount = (2500-(other.getGold()+this->getGold()))*(-1);
            this->setGold(amount);
            other.setGold(amount*(-1));
        }
        else{
            this->setGold(70);
            other.setGold(-70);
        }
    }
}

