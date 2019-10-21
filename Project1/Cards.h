#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
//Primary Base class (non Inheritance)  Aggregation Hierarchy

const char suits[] = { 'H','S','D','C' };

class Cards
{
public:
	Cards() : suit('\n'), rank("\n"), value(0) {};
	Cards(char, std::string);
	void setRank();
	void createCard(char, int);
	void printCard();
	Cards* deal(size_t, Cards * deck);
	Cards operator = (Cards& src) {
		this->rank = src.rank;
		this->suit = src.suit;
		this->value = src.value;
		return *this;
	}
	bool  operator == (Cards& rhs) { return (this->suit == rhs.suit && this->rank == rhs.rank) ? true : false; }
	bool  operator != (Cards& rhs) { return (this->suit != rhs.suit && this->rank != rhs.rank) ? true : false; }
	Cards getCard() {
		return *this;
	}
private:
	
	char suit;
	std::string rank;
	int value;
};
