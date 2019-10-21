#pragma once
#include "Cards.h"

//Manages the deck rsources
class Deck
{
public:
	Deck();
	~Deck();
	void printDeck();
	Cards* getDeck() { return this->deck; }
	size_t count() { return this->size; }
	void addDelt(Cards& obj);
	std::vector<Cards>& getDelt();
private:
	Cards  deck[52];
	std::vector <Cards> dealed;
	size_t size = 52;
};
