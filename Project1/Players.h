#pragma once
#include "Cards.h"
#include "Deck.h"

//Class to manage player resources
class Players	
{
	std::string name;
	Cards *hand;
	size_t count;
	size_t score;
public:
	Players() : name("\n"), hand(nullptr), count(0), score(0) {};
	Players(std::string name, Cards* hand, size_t count);
	void seeHand();
	void setPlayer(std::string name, Cards* hand, size_t count);
	size_t Count() { return this->count; };
	void draw(Deck *);
	void evaluate();

	~Players();
};

