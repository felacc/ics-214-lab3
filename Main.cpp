#include "Cards.h"
#include <iostream>

int main()
{	
	srand(static_cast<unsigned int>(time(0))); // seed randomizer

	//int pickCount = getPickCountNeededForFourSuits(false);
	//std::cout << "Number of picks: " << pickCount  << '\n';
	int iterations = 100000;
	int totalPickCount{};
	for (int i = 0; i < iterations; i++)
	{
		totalPickCount += getPickCountNeededForFourSuits(false, false);
	}

	std::cout << "Average: " << static_cast<double>(totalPickCount) / iterations << '\n';
}