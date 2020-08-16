//
// Created by itaik on 03/01/2019.
//

#ifndef ASSIGNMENT5_GAME_H
#define ASSIGNMENT5_GAME_H

#include "Warrior.h"
#include "Necromancer.h"
#include "Thief.h"
#include <vector>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>

enum GameParameters{
    NUM_WARRIOR = 0,
    NUM_THIEF = 1,
    NUM_NECRO = 2,
    NUM_ROUND = 3,
    NUM_PLAYER=4,
    AMOUNT_TURN = 5,
    CURR_TURN = 6,
    SPEC_ABILITY= 7,
    GET_MONEY=8,
};

enum PlayerParameter{
    NAME_HERO = 0,
    TYPE_HERO = 1,
    GOLD_PLAYER = 2,
    NUM_DRAG = 3,
    NUM_WIZ = 4,
    NUM_ARCH = 5,
    NUM_VAMP = 6,
    NUM_ZOMB = 7
};

class Game {
private:
    int numOfRound;
    int amountOfTurns;
    int currentTurn;
    int numOfPlayers;
    vector<Hero*> players;
    int numWars;
    int numThief;
    int numNecro;
    bool didYouUseSpecial;
    bool didYouGetYourGold;
    void createPlayers(int numOfWars, int numOfThiefs, int numOfNecros);
public:
    Game(int numOfWars, int numOfThiefs, int numOfNecros);
    Game(int number);
    void play();
    ~Game();
};


#endif //ASSIGNMENT5_GAME_H
