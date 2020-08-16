//
// Created by itaik on 05/01/2019.
//

#ifndef ASSIGNMENT5_GAMEEXCEPTION_H
#define ASSIGNMENT5_GAMEEXCEPTION_H

#include <iostream>
#include "string"

using namespace std;

class GameException{

public:
	virtual ~GameException(){};
    virtual void Handle()const=0;
};

class CorruptUserException : public GameException{
    string m_name;
public:
    CorruptUserException() throw(): GameException(){};
    ~CorruptUserException() throw(){};
    CorruptUserException(string name) throw():GameException(),m_name(name){};
    virtual void Handle()const throw() { cout << "The name you've entered isn't legal: " << m_name << "\n"; }
};

class OutOfAmountException : public GameException{
    int m_value;
public:
    OutOfAmountException() throw(){m_value = 10;};
    ~OutOfAmountException() throw(){};
    OutOfAmountException(int value) throw():GameException(),m_value(value){};
    virtual void Handle()const throw(){ cout << "You don't have enough gold to make this purchase: " << m_value << "\n";}
};

class WrongAttackException : public GameException{
    string m_creature;
public:
    WrongAttackException() throw(): GameException(){};
    ~WrongAttackException() throw(){};
    WrongAttackException(string creature) throw():GameException(),m_creature(creature){};
    virtual void Handle()const throw(){ cout << "Cannot perform this action because there is no such creature in the army: " << m_creature << "\n";}
};

class InvalidHeroException : public GameException{
    string m_hero;
public:
    InvalidHeroException() throw(): GameException(){};
    ~InvalidHeroException() throw(){};
    InvalidHeroException(string hero) throw():GameException(),m_hero(hero){};
    virtual void Handle()const throw(){ cout << "The hero's name you have entered doesn't exist: " << m_hero << "\n";}
};

#endif //ASSIGNMENT5_GAMEEXCEPTION_H
