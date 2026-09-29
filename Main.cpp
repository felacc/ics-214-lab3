#include "Cards.h"
#include <iostream>

int main()
{	
	srand(static_cast<unsigned int>(time(0))); // seed randomizer

	int pickCount{};
	for (int i = 0; i < 3; i++)
	{
		pickCount = getPickCountNeededForFourSuits();
		std::cout << "Number of picks for iteration [" << i << "]: " << pickCount << '\n' << '\n';
	}

	int iterations = 10000000;

	// With Replacement
	int totalPickCountWithReplacement{};
	for (int i = 0; i < iterations; i++)
	{
		totalPickCountWithReplacement += getPickCountNeededForFourSuits(false);
	}
	std::cout << "Average for 4 suits (random with replacement): " << static_cast<double>(totalPickCountWithReplacement) / iterations << '\n' << '\n';

	// Without Replacement
	int totalPickCountWithoutReplacement{};
	for (int i = 0; i < iterations; i++)
	{
		totalPickCountWithoutReplacement += getPickCountNeededForFourSuits(false, false);
	}
	std::cout << "Average for 4 suits (random without replacement): " << static_cast<double>(totalPickCountWithoutReplacement) / iterations << '\n' << '\n';

}