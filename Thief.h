//
// Created by tomer on 30/12/2018.
//

#ifndef ASSIGNMENT5_THIEF_H
#define ASSIGNMENT5_THIEF_H
#include "Hero.h"
class Thief : public Hero
{
public:
    Thief();
    Thief(string newName);
    Thief(string thiName, string thiType, string thiGold, string thiDrag, string thiWiz,string thiArch, string thiVamp, string thiZomb);
    ~Thief();
    void specialAbility(Hero& other);
};

#endif //ASSIGNMENT5_THIEF_H
