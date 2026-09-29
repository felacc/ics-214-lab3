#include "Cards.h"
#include <iostream>

int main()
{	
	srand(static_cast<unsigned int>(time(0))); // seed randomizer

	int pickCount = getPickCountNeededForFourSuits();
	std::cout << "Number of picks: " << pickCount  << '\n';
}