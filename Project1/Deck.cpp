#include "Deck.h"



Deck::Deck()
{
	size_t cnt = 0;
	bool delt = false;
	size_t i = 0;
	size_t counter = 0;
	while (cnt < 52)
	{
		this->deck[cnt].createCard(suits[counter], i + 1);
		++i;
		++cnt;
		if (i == 13) {
			counter++;
			i = 0;
		}
	}
	delt = 0;
}
void Deck::printDeck()
{
	for (Cards& c : deck)
	{
		c.printCard();
	}
}

void Deck::addDelt(Cards & obj)
{
	this->dealed.push_back(obj);
}
std::vector<Cards> & Deck::getDelt()
{
	
	return this->dealed;
}

Deck::~Deck()
{
}
