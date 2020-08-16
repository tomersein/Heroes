//
// Created by itaik on 03/01/2019.
//

#include "Game.h"

Game::Game(int numOfWars, int numOfThiefs, int numOfNecros) {
	numOfRound = 1;
	amountOfTurns = 1;
	numOfPlayers = numOfWars + numOfThiefs + numOfNecros;
	createPlayers(numOfWars, numOfThiefs, numOfNecros);
	srand(time(NULL));
	currentTurn = rand() % numOfPlayers + 1;
	numWars=numOfWars;
	numThief=numOfThiefs;
	numNecro=numOfNecros;
	didYouGetYourGold = false;
	didYouUseSpecial = false;
}

Game::~Game(){

}

Game::Game(int number){
	ifstream reader;
	string line="";
	int counterGame = 0;
	string lines[9];

	reader.open("Game/Game.txt");
	while(getline(reader,line)){
		if (counterGame < 9) {
			lines[counterGame] = line;
			counterGame++;
		}
		else if (counterGame >= 9) {
			int counterPlayer = 0;
			ifstream readerPlayer;
			string plines[8];
			string playerPath = "Game/Heroes/" + line + "/" + line + ".txt";
			readerPlayer.open(playerPath.c_str());
			string playerLine="";
			while(getline(readerPlayer, playerLine)){
				plines[counterPlayer] = playerLine;
				counterPlayer++;
			}
			if (plines[TYPE_HERO] == "Warrior") {
				players.push_back(new Warrior(plines[NAME_HERO], plines[TYPE_HERO], plines[GOLD_PLAYER],
						plines[NUM_DRAG], plines[NUM_WIZ], plines[NUM_ARCH],
						plines[NUM_VAMP], plines[NUM_ZOMB]));
			} else if (plines[TYPE_HERO] == "Thief") {
				players.push_back(new Thief(plines[NAME_HERO], plines[TYPE_HERO], plines[GOLD_PLAYER],
						plines[NUM_DRAG], plines[NUM_WIZ], plines[NUM_ARCH], plines[NUM_VAMP],
						plines[NUM_ZOMB]));
			} else if (plines[TYPE_HERO] == "Necromancer") {
				players.push_back(new Necromancer(plines[NAME_HERO], plines[TYPE_HERO], plines[GOLD_PLAYER],
						plines[NUM_DRAG], plines[NUM_WIZ], plines[NUM_ARCH],
						plines[NUM_VAMP], plines[NUM_ZOMB]));
			}
			readerPlayer.close();
			remove(playerPath.c_str());
			string removeFile = "Game/Heroes/" + line + "/";
			remove(removeFile.c_str());
		}
	}
	reader.close();
	string removeGameText = "Game/Game.txt";
	remove(removeGameText.c_str());
	string removeHeroesFile = "Game/Heroes/";
	remove(removeHeroesFile.c_str());
	string removeGameFile = "Game/";
	remove(removeGameFile.c_str());



	numOfRound = atoi(lines[NUM_ROUND].c_str());
	amountOfTurns = atoi(lines[AMOUNT_TURN].c_str());
	numOfPlayers = atoi(lines[NUM_PLAYER].c_str());
	currentTurn = atoi(lines[CURR_TURN].c_str());
	didYouGetYourGold = atoi(lines[GET_MONEY].c_str());
	didYouUseSpecial = atoi(lines[SPEC_ABILITY].c_str());
	numWars = atoi(lines[NUM_WARRIOR].c_str());
	numThief = atoi(lines[NUM_THIEF].c_str());
	numNecro = atoi(lines[NUM_NECRO].c_str());
}

void Game::createPlayers(int numOfWars, int numOfThiefs, int numOfNecros) {
	string heroName;
	bool goodName = false;
	for(int i=0; i<numOfWars; i++){
		while(!goodName) {
			try {
				cout << "Please insert warrior number " << i + 1 << " name:\n";
				cin >>ws;
				getline(cin, heroName);
				for(int j=0; j<(int)heroName.length(); j++){
					char letterInName = heroName[j];
					if(letterInName == ' '){
						throw CorruptUserException(heroName);
					}
				}
				players.push_back(new Warrior(heroName));
				goodName = true;
			}
			catch(GameException& error){
				error.Handle();
			}
		}
		goodName = false;
	}
	goodName = false;
	for(int i=0; i<numOfThiefs; i++){
		while(!goodName) {
			try {
				cout << "Please insert thief number " << i + 1 << " name:\n";
				cin >>ws;
				getline(cin, heroName);
				for(int j=0; j<(int)heroName.length(); j++){
					char letterInName = heroName[j];
					if(letterInName == ' '){
						throw CorruptUserException(heroName);
					}
				}
				players.push_back(new Thief(heroName));
				goodName = true;
			}
			catch(GameException& error){
				error.Handle();
			}
		}
		goodName = false;
	}
	goodName = false;
	for(int i=0; i<numOfNecros; i++){
		while(!goodName) {
			try {
				cout << "Please insert necromancer number " << i + 1 << " name:\n";
				cin >>ws;
				getline(cin, heroName);
				for(int j=0; j<(int)heroName.length(); j++){
					char letterInName = heroName[j];
					if(letterInName == ' '){
						throw CorruptUserException(heroName);
					}
				}
				players.push_back(new Necromancer(heroName));
				goodName = true;
			}
			catch(GameException& error){
				error.Handle();
			}
		}
		goodName = false;
	}
}

void Game::play() {
	bool didGameEnd = false;
	/*
	 * infinite loop until the game ends or a player hits "exit", which will result a "return" statement
	 */
	while(!didGameEnd) {
		if((amountOfTurns % (players.size()+1)) == 0){
			numOfRound++;
		}
		if(currentTurn>(int)players.size()){
			currentTurn = 1;
		}
		vector<Hero *>::iterator it = players.begin()+currentTurn-1;
		Hero *currPlayer = *it;
		bool didYouFinishYourTurn = false; //indicates if a player finished his turn yet
		while (!didYouFinishYourTurn) {
			cout << "Welcome " + currPlayer->getName() << "\n" << "What is your next step in the path to victory?\n";
			cout << "1. Attack\n" << "2. Get daily gold\n" << "3. Buy creatures\n" << "4. Show details\n" << "5. Special skill\n" << "6. End of my turn\n" << "7. Exit\n";
			int number;
			cin >> number;
			switch (number) {
			case 1: {
				cout << "1. Show me my opponents\n" << "2. Attack hero\n";
				int secondNum;
				cin >> secondNum;
				switch (secondNum) {
				case 1: {
					vector<Hero *>::iterator details;
					for (details = players.begin(); details != players.end(); details++) {
						Hero *temp = *details;
						if(temp->getName()!=currPlayer->getName()) {
							cout << temp->getName() << " " << temp->getType() << "\n";
						}
					}
					break;
				}
				case 2: {
					if(numOfRound<4){
						cout << "You cannot attack any hero until the forth round.\n";
						break;
					}
					bool goodName = false;
					string name;
					while(!goodName) {
						try {
							cout << "Please insert your opponent name:\n";
							cin >> name;
							vector<Hero *>::iterator isAName;
							for (isAName = players.begin(); isAName != players.end(); isAName++) {
								Hero *temp = *isAName;
								if(temp->getName()==name)
									goodName = true;
							}
							if(!goodName)
								throw InvalidHeroException(name);
						}
						catch(GameException& error){
							error.Handle();
						}
					}
					vector<Hero *>::iterator it2;
					int count = 0; // to know which one to delete later on from players
					for (it2 = players.begin(); it2 != players.end(); it2++) {
						Hero *temp = *it2;
						if (temp->getName() == name) {
							if (!(currPlayer->fight(*temp)))
							{
								cout << "You have been perished\n";
								temp->setGold(currPlayer->getGold());
								if(currPlayer->getType() == "Warrior"){
									this->numWars--;
								}
								else if(currPlayer->getType() == "Thief"){
									this->numThief--;
								}
								else{
									this->numNecro--;
								}
								delete currPlayer;
								players.erase(players.begin() + currentTurn-1);
								didYouFinishYourTurn = true;
								numOfPlayers--;
								currentTurn++;
								amountOfTurns++;
								if (players.size() == 1) {
									cout << temp->getName() << " is the winner!\n";
									// removing last player from the game
									delete temp;
									return;
								}
							} else {
								cout << "You have been victorious\n";
								currPlayer->setGold(temp->getGold());
								numOfPlayers--;
								if(currPlayer->getType() == "Warrior"){
									this->numWars--;
								}
								else if(currPlayer->getType() == "Thief"){
									this->numThief--;
								}
								else{
									this->numNecro--;
								}
								delete temp;
								players.erase(players.begin() + count);
								if (players.size() == 1) {
									cout << currPlayer->getName() << " is the winner!\n";
									//removing last player from the game
									delete currPlayer;
									return;
								}
							}
							break;
						}
						count++;
					}
					break;
				}
				default:
					cout << "You have entered an illegal number\n"; // check later
					break;
				}
				break;
			}
			case 2: {
				if (!didYouGetYourGold) {
					didYouGetYourGold = true;
					currPlayer->setGold(100);
				} else {
					cout << "You have already collected your daily gold this turn.\n";
				}
				break;
			}
			case 3: {
				int secondNum;
				cout << "1. Buy Zombies.\n" << "2. Buy Archers.\n" << "3. Buy Vampires.\n" << "4. Buy Wizard.\n"
						<< "5. Buy Black Dragon.\n";
				cin >> secondNum;
				try {
					switch (secondNum) {
					case 1: {
						Zombie *temp = new Zombie();
						temp->details();
						int amount; // player needs to state how many he wants to buy
						cin >> amount;
						string heroType = temp->getType();
						currPlayer->buyCreatures(heroType, amount);
						delete temp;
						break;
					}
					case 2: {
						Archer *temp = new Archer();
						temp->details();
						int amount;
						cin >> amount;
						string heroType = temp->getType();
						currPlayer->buyCreatures(heroType, amount);
						delete temp;
						break;
					}
					case 3: {
						Vampire *temp = new Vampire();
						temp->details();
						int amount;
						cin >> amount;
						string heroType = temp->getType();
						currPlayer->buyCreatures(heroType, amount);
						delete temp;
						break;
					}
					case 4: {
						Wizard *temp = new Wizard();
						temp->details();
						int amount;
						cin >> amount;
						string heroType = temp->getType();
						currPlayer->buyCreatures(heroType, amount);
						delete temp;
						break;
					}
					case 5: {
						Black_Dragon *temp = new Black_Dragon();
						temp->details();
						int amount;
						cin >> amount;
						string heroType = temp->getType();
						currPlayer->buyCreatures(heroType, amount);
						delete temp;
						break;
					}
					default: {
						cout << "Illegal option was received, please try again\n";
					}
					}
					break;
				}
				catch(GameException& error){
					error.Handle();
				}
				break;
			}
			case 4: {
				currPlayer->showDetails(); //the function was built completely inside Hero.cpp
				break;
			}
			case 5: {
				if(didYouUseSpecial){
					cout << "You have already used your special ability this turn.\n";
					break;
				}
				if (currPlayer->getType() == "Warrior") {
					currPlayer->specialAbility(*currPlayer);
					cout << "Gold added successfully\n";
				}
				if (currPlayer->getType() == "Thief") {
					string heroToStealFrom;
					bool goodName = false;
					while(!goodName) {
						try {
							cout << "Please insert hero name:\n";
							cin >> heroToStealFrom;
							vector<Hero *>::iterator isAName;
							for (isAName = players.begin(); isAName != players.end(); isAName++) {
								Hero *temp = *isAName;
								if (temp->getName() == heroToStealFrom) {
									goodName = true;
								}
							}
							if(!goodName){
								throw InvalidHeroException(heroToStealFrom);
							}
						}
						catch(GameException& error){
							error.Handle();
						}
					}
					vector<Hero *>::iterator stealFrom;
					for (stealFrom = players.begin(); stealFrom != players.end(); stealFrom++) {
						Hero *temp = *stealFrom;
						if (temp->getName() == heroToStealFrom) {
							currPlayer->specialAbility(*temp);
							break;
						}
					}
				}
				if (currPlayer->getType() == "Necromancer") {
					currPlayer->specialAbility(*currPlayer);
					cout << "Zombie added successfully\n";
				}
				didYouUseSpecial = true;
				break;
			}
			case 6: {
				didYouFinishYourTurn = true;
				currentTurn++;
				amountOfTurns++;
				didYouGetYourGold = false;
				didYouUseSpecial = false;
				break;
			}
			case 7: {
				mkdir("Game/",0777);
				ofstream writer;
				string txtGameString="Game/Game.txt";
				writer.open(txtGameString.c_str());
				writer << numWars << endl;
				writer << numThief << endl;
				writer << numNecro << endl;
				writer << numOfRound << endl;
				writer << numOfPlayers << endl;
				writer << amountOfTurns << endl;
				writer << currentTurn << endl;
				writer << didYouUseSpecial << endl;
				writer << didYouGetYourGold << endl;
				for (it = players.begin(); it != players.end(); it++) {
					Hero *temp = *it;
					string nameHero = temp->getName();
					writer << nameHero <<endl;
				}
				writer.close();
				mkdir("Game/Heroes/",0777);
				//now we will write files for each hero
				vector<Hero *>::iterator it;
				for (it = players.begin(); it != players.end(); it++) {
					Hero *temp = *it;
					string nameOfHero;
					nameOfHero=temp->getName();
					ofstream playerWriter;
					string pathHero;
					pathHero="Game/Heroes/"+nameOfHero+"/";
					const char * fileHeroPath = pathHero.c_str();
					mkdir(fileHeroPath,0777);
					string txtPathPlayer;
					txtPathPlayer=pathHero+nameOfHero+".txt";
					writer.open(txtPathPlayer.c_str());
					int goldPlayer;
					goldPlayer=temp->getGold();
					string typePlayer;
					typePlayer=temp->getType();
					int numDragon;
					numDragon=temp->getDragon();
					int numWizard;
					numWizard=temp->getWizard();
					int numArcher;
					numArcher=temp->getArcher();
					int numVampire;
					numVampire=temp->getVampire();
					int numZombie;
					numZombie=temp->getZombie();
					writer << nameOfHero << endl;
					writer << typePlayer << endl;
					writer << goldPlayer << endl;
					writer << numDragon << endl;
					writer << numWizard << endl;
					writer << numArcher << endl;
					writer << numVampire << endl;
					writer << numZombie << endl;
					writer.close();
				}
				vector<Hero *>::iterator deletingHero;
				for (int i=0; i<(int)players.size(); i++) {
					Hero* removePlayer = players[i];
					delete removePlayer;
				}
				return;
			}
			default: {
				cout << "Please insert a legal number\n";
				break;
			}
			}
		}
	}
}
