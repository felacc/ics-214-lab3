#include "Cards.h"
#include <iostream>

int main()
{	
	srand(static_cast<unsigned int>(time(0))); // seed randomizer

	int card{ pickRandomCard() };
	std::cout << "Random Card Index: " << card << '\n';

	Rank rank{ getRank(card) };
	std::cout << "Rank: " << Constants::RANKS[static_cast<int>(rank)] << '\n';

}