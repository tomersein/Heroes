#include "Game.h"
using namespace std;


//
int main(int argc, char* argv[]) {
	Game* heroesGame;
    if (argc == 2) {
        heroesGame = new Game(1);
        heroesGame->play();
    } else {
        try {
            int numberOfWars = atoi(argv[2]);
            int numberOfThiefs = atoi(argv[3]);
            int numberOfNecros = atoi(argv[4]);
            if (numberOfNecros > 3 || numberOfNecros < 0 || numberOfThiefs > 3 || numberOfThiefs < 0 ||
                numberOfWars > 3 || numberOfWars < 0) {
                throw "The number of plays is illegal - game cannot start properly.\n"; //check tomorrow what to do here
            }
            heroesGame = new Game(numberOfWars, numberOfThiefs, numberOfNecros);
            heroesGame->play();
        }
        catch (string &error) {
            cout << error;
            return 2;
        }
    }
    delete heroesGame;
    return 0;
}
