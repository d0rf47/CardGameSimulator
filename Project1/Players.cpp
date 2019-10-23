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

void Players::evaluate(Players**)
{


}