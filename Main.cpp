#include "Cards.h"
#include <iostream>

int main()
{	
	srand(static_cast<unsigned int>(time(0))); // seed randomizer

	int card{ pickRandomCard() };
	std::cout << "Random Card Index: " << card << '\n';

	Rank rank{ getRank(card) };
	std::cout << "Rank: " << Constants::RANKS[static_cast<int>(rank)] << '\n';

	Suit suit{ getSuit(card) };
	std::cout << "Suit: " << Constants::SUITS[static_cast<int>(suit)] << '\n';

	bool trueArr[] = { true, true, true, true };

	bool falseArr[] = { true, false, true, true };

	std::cout << "True arr: " << allArrayElementsAreTrue(trueArr, 4) << '\n';   // note: hardcoding size for convience and testing
	std::cout << "False arr: " << allArrayElementsAreTrue(falseArr, 4) << '\n'; // note: hardcoding size for convience and testing

}