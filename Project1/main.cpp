#include "Cards.h"
#include "Deck.h"
#include "Players.h"

int main() {
	srand(time(NULL));			// Seed gen for the random Number gen used for dealing cards
	Cards c1;					//instantiates dummy card to deal hands
	Deck d1;					// creates a 52 card deck
	Players *P;					// allows unlimted number of players with name hand card count	
	size_t cardCount = 0;		// Allocated number for number of cards for the hand (2) (5) or (7) card stud
	std::string name;			// each players name
	int players = 0;			// number of players
	
	//beginning of main game
	std::cout << "How many Players:  ";
	std::cin >> players;
	std::cout << "Card Count { (2), (5) or (7) } :";
	std::cin >> cardCount;
	
	P = new Players[players];						//creates array of players
	
	for (int i = 0; i < players; i++) {
		std::cout << "Enter player" << i << " Name :";				
		std::cin >> name;			
		P[i].setPlayer(name, c1.deal(cardCount,d1.getDeck()), cardCount);			// deals a hand of the specified number of cards for each player
	}

	for (int i = 0; i < players; i++) {
		P[i].seeHand();																// displays each players hand
		P[i].draw(&d1);
		P[i].seeHand();
		system("pause");
		system("cls");
	}
	for (int i = 0; i < players; i++) {
		P[i].seeHand();
		P[i].evaluate();
		std::cout << "------------------" << std::endl;
	}
	return 0;
}


