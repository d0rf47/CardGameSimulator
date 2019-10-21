#include "Cards.h"



std::vector <int> delt;						// tracks the indecies of the cards already delt to ensure no duplicates are delt
int roll(int min, int max)					// random num gen to generate random numbers for the deck index (used to deal)
{
	double x = 0;
	int that = 0;
	x = rand() / static_cast<double>(RAND_MAX + 1);
	that = min + static_cast<int>(x * (max - min));
	for (size_t i = 0; i < delt.size(); i++) {
		
		if (that == delt[i]) {
			x = rand() / static_cast<double>(RAND_MAX + 1);
			that = min + static_cast<int>(x * (max - min));
		}
		
	}	
	delt.push_back(that);
	return that;
}

void Cards::setRank()							// sets the cards rank (King, Queen Ace Jack etc)
{
	if (this->value < 2) {
		rank = "A";
	}
	else if (this->value == 11) {
		rank = "J";
	}
	else if (this->value == 12)
	{
		rank = "Q";
	}
	else if (this->value == 13)
	{
		rank = "K";
	}
	else
	{
		rank = std::to_string(this->value);
	}
}

Cards::Cards(char  suit, std::string rank)					//2-arg Ctor
{
	for (int i = 0; i < 4; i++) {
		if (suit == suits[i]) {
			this->suit = suit;
			break;
		}
	}
	this->rank = rank;


}
void Cards::createCard(char suit, int value)			//Used to generate cards
{
	this->suit = suit;
	this->value = value;
	this->setRank();
}

void Cards::printCard()									//prints the current card (called in the Players Hand)
{
	std::cout << rank << " of " << suit << std::endl;
}

Cards* Cards::deal(size_t cardCount, Cards * deck)			//Most important function Deals the cards for each player (used by C1 dummy obj in Main for deal for new players)
{
	bool located = true;
	size_t c = 0;
	Cards * temp;
	temp = new Cards[cardCount];

	for (size_t i = 0; i < cardCount; i++) {
		c = roll(1, 52);
		temp[i] = deck[c];
	}
	
	return temp;
	
}

