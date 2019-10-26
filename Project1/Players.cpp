#include "Players.h"

//Ctor for basic player
Players::Players(std::string name, Cards * hand, size_t count)
{
	this->name = name;
	this->count = count;
	this->hand = new Cards[count];
	for (size_t i = 0; i < count; i++) {
		this->hand[i] = hand[i];
	}

}

//displays the full hand for the current player
void Players::seeHand()
{

	std::cout << std::endl << "Player : " << this->name << std::endl;
	for (size_t i = 0; i < count; i++) {
		this->hand[i].printCard();
	}
}

//Can also set a player (works same as 3-arg Ctor)
void Players::setPlayer(std::string name, Cards * hand, size_t count)
{
	this->name = name;
	this->count = count;
	this->hand = new Cards[count];
	for (size_t i = 0; i < count; i++) {
		this->hand[i] = hand[i];
	}

}

Players::~Players()
{
	delete[]this->hand;
	this->hand = nullptr;
}

void Players::draw(Deck * d)
{
	size_t num = 0, t;	
	std::vector<size_t> indecies;
	std::cout << "How Many Cards would you like to exchange? ";
	std::cin >> num;
	for (size_t i = 0; i < this->Count(); i++) {
		std::cout << i + 1 << ": "; 
		this->hand[i].printCard();
	}	
	for (size_t i = 0; i < num; i++) {
		std::cout << "Enter the number of the card to exchange : ";
		std::cin >> t;
		--t;
		indecies.push_back(t);
	}
	for (size_t i = 0; i < num; i++) {
		Cards temp;
		temp = *temp.deal(1, d->getDeck());
		this->hand[indecies.back()] = temp;
		indecies.pop_back();
	}

	
}	

void Players::evaluate()
{
	size_t pairCount = 0;
	size_t numOfPairs = 0;
	size_t Score = 0;
	bool found = false;
	int x = 0;
	std::string handRank = "High Card";
	bool highCard = true, Pair = false, twoPair = false, tKind = false, straight = false, flush = false, fullHouse = false, fKind = false, sFlush = false, rFlush = false;
	int suitCounter = 0;
	//check for pairs
	for (size_t i = 0; i < count; i++) {
		x = i + 1;
		while (x < count)
		{
			if (hand[i].getRank() == hand[x].getRank() && &hand[i] != &hand[x]) {
				found = true;
				
				if (Pair && found && pairCount > 0) {
					tKind = true;
					Pair = false;
				}
				
				if (tKind && found && &hand[i] != &hand[x] && pairCount > 0) {
					fKind = true;
					tKind = false;
				}
				if (!tKind && !fKind) {
					Pair = true;
					pairCount++;
					numOfPairs++;
				};
			}
			if (hand[i].getSuit() == hand[x].getSuit() && &hand[i] != &hand[x]) {
				suitCounter++;
			}
			if (suitCounter == 5) {
				flush = true;
			}
			if (Pair && tKind) {
				fullHouse = true;
				Pair = false;
				tKind = false;
			}
			x++;
			found = false;
		}
		pairCount = 0;
	}

	if (Pair) {
		std::cout << "Pair" << std::endl;
	}
	else if (numOfPairs > 1)
	{
		std::cout << "Two Pair" << std::endl;
	}else
	if (tKind) {
		std::cout << "Three of a Kind" << std::endl;
	}else
	if (fKind) {
		std::cout << "Four of a Kind" << std::endl;
	}else
	if (fullHouse) {
		std::cout << "Full House" << std::endl;
	}else
	if (flush) {
		std::cout << "Flush" << std::endl;
	}
	else
	{
		std::cout << "High Card" << std::endl;
	}
	
}