//
// Created by itaik on 27/12/2018.
//

#include "Hero.h"

Hero::~Hero() {
    delete[] army;
}
Hero::Hero() {
    name = "hero";
    type = "";
    gold = 0;
    army = new int[5];
    for(int i=0; i<NUMBER_OF_CREATURES; i++){
        army[i] = 0;
    }
}

Hero::Hero(string heroName, string typeHero, string goldHero, string numDrag, string numWiz, string numArch, string numVamp, string numZomb){
    name=heroName;
    type=typeHero;
    gold = atoi(goldHero.c_str());
    army = new int[5];
    army[BLACK_DRAGON]=atoi(numDrag.c_str());
    army[WIZARD]=atoi(numWiz.c_str());
    army[VAMPIRE]=atoi(numVamp.c_str());
    army[ARCHER]=atoi(numArch.c_str());
    army[ZOMBIE]=atoi(numZomb.c_str());
}

void Hero::showDetails() {
    string heroDetails;
    cout << name << " " << type << ":\n" << gold << " gold\n";
    int i = 0;
    bool HasUnits = false;
    while (i < NUMBER_OF_CREATURES) {
        if (army[i] > 0) {
        	stringstream temp;
            if (i == BLACK_DRAGON) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails = heroDetails + numberAsString + " Black_Dragon ";
                HasUnits = true;
            } else if (i == WIZARD) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails = heroDetails + numberAsString + " Wizard ";
                HasUnits = true;
            } else if (i == ARCHER) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Archer ";
                HasUnits = true;
            } else if (i == VAMPIRE) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Vampire ";
                HasUnits = true;
            } else if (i == ZOMBIE) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Zombie ";
                HasUnits = true;
            }
        }
        i++;
    }
    if (HasUnits) {
        heroDetails.erase(heroDetails.length() - 1, 1);
        heroDetails = heroDetails + ".";
    }

    cout << heroDetails << "\n";
}


void Hero::showDetailsWithoutGold() {
    string heroDetails;
    cout << name << " " << type << ":\n";
    int i = 0;
    bool HasUnits = false;
    while (i < NUMBER_OF_CREATURES) {
        if (army[i] > 0) {
        	stringstream temp;
            if (i == BLACK_DRAGON) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Black_Dragon ";
                HasUnits = true;
            } else if (i == WIZARD) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Wizard ";
                HasUnits = true;
            } else if (i == ARCHER) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Archer ";
            } else if (i == VAMPIRE) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Vampire ";
            } else if (i == ZOMBIE) {
            	int number = army[i];
            	temp << number;
            	std::string numberAsString(temp.str());
                heroDetails += numberAsString + " Zombie ";
                HasUnits = true;
            }
        }
        i++;
    }
    if (HasUnits) {
        heroDetails.erase(heroDetails.length() - 1, 1);
        heroDetails = heroDetails + ".";
    }

    cout << heroDetails << "\n";
}

bool Hero::buyCreatures(const string& other, int amount){
    if(amount<=0){
        return false;
    }
    if(other=="Wizard"){
        if(150*amount > gold){
            throw OutOfAmountException(gold);
        }
        gold = gold - (150*amount);
        this->army[WIZARD]=army[WIZARD]+amount;
        return true;
    }
    else if(other=="Vampire"){
        if(80*amount>gold){
            throw OutOfAmountException(gold);
        }
        gold = gold - (80*amount);
        this->army[VAMPIRE]=army[VAMPIRE]+amount;
        return true;
    }
    else if(other=="Archer"){
        if(90*amount>gold){
            throw OutOfAmountException(gold);
        }
        this->army[ARCHER]=army[ARCHER]+amount;
        gold = gold - (90*amount);

        return true;
    }
    else if(other=="Zombie"){
        if(50*amount>gold){
            throw OutOfAmountException(gold);
        }
        gold = gold - (50*amount);
        this->army[ZOMBIE]=army[ZOMBIE]+amount;
    }
    else if(other=="Black_Dragon"){
        if(200*amount>gold){
            throw OutOfAmountException(gold);
        }
        gold = gold - (200*amount);
        this->army[BLACK_DRAGON]=army[BLACK_DRAGON]+amount;
    }
    else{
       cout << other << " Isn't a valid creature name.\n";
       return false;
    }
    return true;
}

string Hero::getName(){
    string temp = name;
    return temp;
}

bool Hero::setName(const string& newName) {
    if(newName.length() > 31)
        return false;
    for(int i = 0; i<(int)newName.length(); i++){
        if(!((newName[i]>='0' && newName[i] <= '9') || (newName[i] <= 'Z' && newName[i] >= 'A') || ((newName[i] <= 'z' && newName[i] >= 'a'))))
            return false;
    }
    name = newName;
    return true;
}

bool Hero::setGold(int num){
    gold = gold + num;
    if(gold>2500)
        gold = 2500;
    if(gold<0)
        gold = 0;
    return true;
}

int Hero::getGold() {
    return gold;
}

bool Hero::fight(Hero& other){
    string creaturesName[] = {"Black_Dragon", "Wizard", "Archer", "Vampire", "Zombie"};
    bool thisTurn = true;
    string attackingCreature;
    string attackedCreature;
    Creature* attacker;
    Creature* defender;
    int attackingIndex = -1; //initializing with -1, since 0 got a meaning in this syntax
    int defendingIndex = -1;
    while(!(other.isArmyDefeated()) && !(this->isArmyDefeated())){
        if(thisTurn) {
            this->showDetailsWithoutGold();
            other.showDetailsWithoutGold();
            thisTurn = false;
            cout << this->name << "'s turn:\n";
            bool goodNames = false;
            while(!goodNames) {
                try {
                    cin >> attackingCreature;
                    cin >> attackedCreature;
                    bool goodAttacker = false;
                    bool goodAttacked = false;
                    for (int i = 0; i < 5; i++) {
                        if (creaturesName[i] == attackingCreature) {
                            attackingIndex = i;
                            goodAttacker = true;
                        }
                        if (creaturesName[i] == attackedCreature) {
                            defendingIndex = i;
                            goodAttacked = true;
                        }
                    }
                    if (!goodAttacker) {
                        throw WrongAttackException(attackingCreature);
                    }
                    if (!goodAttacked) {
                        throw WrongAttackException(attackedCreature);
                    }
                    if (this->army[attackingIndex] == 0) {
                        throw WrongAttackException(attackingCreature);
                    }
                    if (other.army[defendingIndex] == 0) {
                        throw WrongAttackException(attackedCreature);
                    }
                    goodNames = true;
                }
                catch(GameException& error){
                    error.Handle();
                }
            }
            attacker = identifyCreatureByName(attackingCreature);
            defender = identifyCreatureByName(attackedCreature);
            int attackPoints = attacker->fight(*defender, this->army[attackingIndex]);
            int killed = defender->defend(*attacker, attackPoints);
            other.army[defendingIndex] = other.army[defendingIndex] - killed;
            if (other.army[defendingIndex] < 0) {
                other.army[defendingIndex] = 0;
            }
            delete attacker;
            delete defender;
            continue;
        }
        else{
            other.showDetailsWithoutGold();
            this->showDetailsWithoutGold();
            thisTurn = true;
            cout << other.name << "'s turn:\n";
            bool goodNames = false;
            while(!goodNames) {
                try {
                    cin >> attackingCreature;
                    cin >> attackedCreature;
                    bool goodAttacker = false;
                    bool goodAttacked = false;
                    for (int i = 0; i < 5; i++) {
                        if (creaturesName[i] == attackingCreature) {
                            goodAttacker = true;
                            attackingIndex = i;
                        }
                        if (creaturesName[i] == attackedCreature) {
                            defendingIndex = i;
                            goodAttacked = true;
                        }
                    }
                    if (!goodAttacker) {
                        throw WrongAttackException(attackingCreature);
                    }
                    if (!goodAttacked) {
                        throw WrongAttackException(attackedCreature);
                    }
                    if (other.army[attackingIndex] == 0) {
                        throw WrongAttackException(attackingCreature);
                    }
                    if (this->army[defendingIndex] == 0) {
                        throw WrongAttackException(attackedCreature);
                    }
                    goodNames = true;
                }
                catch(GameException& error){
                    error.Handle();
                }
            }
            attacker = identifyCreatureByName(attackingCreature);
            defender = identifyCreatureByName(attackedCreature);
            int attackPoints = attacker->fight(*defender, other.army[attackingIndex]);
            int killed = defender->defend(*attacker, attackPoints);
            this->army[defendingIndex] = this->army[defendingIndex] - killed;
            if (this->army[defendingIndex] < 0) {
                this->army[defendingIndex] = 0;
            }
            delete attacker;
            delete defender;
        }
    }
    return(other.isArmyDefeated());
}

bool Hero::isArmyDefeated() {
    return(army[ZOMBIE]==0 && army[VAMPIRE] == 0 && army[ARCHER] == 0
    && army[WIZARD] == 0 && army[BLACK_DRAGON] == 0);
}

Creature* Hero::identifyCreatureByName(string name) {
    if(name == "Zombie") {
        Zombie* temp = new Zombie();
        return temp;
    }
    if(name == "Vampire") {
        Vampire *temp = new Vampire();
        return temp;
    }
    if(name == "Archer") {
        Archer *temp = new Archer();
        return temp;
    }
    if(name == "Wizard") {
        Wizard *temp = new Wizard();
        return temp;
    }
    if(name == "Black_Dragon") {
        Black_Dragon *temp = new Black_Dragon();
        return temp;
    }
    return NULL; //should never reach this position, or we return null
}

string Hero::getType(){
	return type;
}

int Hero::getDragon(){
    return this->army[BLACK_DRAGON];
}
int Hero::getWizard(){
    return this->army[WIZARD];
}
int Hero::getArcher(){
    return this->army[ARCHER];
}
int Hero::getVampire(){
    return this->army[VAMPIRE];
}
int Hero::getZombie(){
    return this->army[ZOMBIE];
}
