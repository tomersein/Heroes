//
// Created by itaik on 28/12/2018.
//

#ifndef ASSIGNMENT5_WARRIOR_H
#define ASSIGNMENT5_WARRIOR_H

#include "Hero.h"


class Warrior : public Hero
{
public:
    Warrior();
    Warrior(string newName);
    Warrior(string warName, string warType, string warGold, string warDrag, string warWiz,string warArch, string warVamp, string warZomb);
    ~Warrior();
    void specialAbility(Hero& other);
    string getType();
};


#endif //ASSIGNMENT5_WARRIOR_H
