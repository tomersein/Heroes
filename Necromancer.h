//
// Created by tomer on 30/12/2018.
//

#ifndef ASSIGNMENT5_NECROMANCER_H
#define ASSIGNMENT5_NECROMANCER_H
#include "Hero.h"

class Necromancer : public Hero
{
public:
    Necromancer();
    Necromancer(string newName);
    Necromancer(string necName, string necType, string necGold, string necDrag, string necWiz,string necArch, string necVamp, string necZomb);
    ~Necromancer();
    void specialAbility(Hero& other);
};

#endif //ASSIGNMENT5_NECROMANCER_H
