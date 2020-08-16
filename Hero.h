//
// Created by itaik on 27/12/2018.
//

#ifndef ASSIGNMENT5_HERO_H
#define ASSIGNMENT5_HERO_H

#include "Vampire.h"
#include "Zombie.h"
#include "Archer.h"
#include "Wizard.h"
#include "Black_Dragon.h"
#include <sstream>

using namespace std;
enum CreatureType{
    BLACK_DRAGON = 0,
    WIZARD = 1,
    ARCHER = 2,
    VAMPIRE = 3,
    ZOMBIE = 4,
    NUMBER_OF_CREATURES = 5,
    };

class Hero{
private:
    string name;
    int gold;
protected:
    string type;
    int* army;
public:
    Hero();
    virtual ~Hero();
    virtual void specialAbility(Hero& other) = 0;
    virtual bool fight(Hero& other);
    void showDetails();
    void showDetailsWithoutGold();
    bool buyCreatures(const string& other, int amount);
    string getName();
    string getType();
    bool setName(const string& newName);
    bool setGold(int num);
    int getGold();
    bool isArmyDefeated();
    Creature* identifyCreatureByName(string name);
    Hero(string heroName, string typeHero, string goldHero,
         string numDrag, string numWiz, string numArch, string numVamp, string numZomb);
    int getDragon();
    int getWizard();
    int getArcher();
    int getVampire();
    int getZombie();
};


#endif //ASSIGNMENT5_HERO_H
