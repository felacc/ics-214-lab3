#include <cstdlib>
#include <iostream>
#include "Cards.h"

int pickRandomCard()
{
	return rand() % 52;
}

Rank getRank(int index)
{
	Rank rank{ index % 13 }; // returns an int from 0-12 used to select rank

	return rank;

}


Suit getSuit(int index)
{
	Suit suit{ index / 13 };// returns an int from 0-3 used to select suit

	return suit;
}

bool allArrayElementsAreTrue(bool elements[], int size)
{
	bool allTrue{ true };
	for (int i = 0; i < size; i++)
	{
		if (!elements[i])
		{
			allTrue = false;
		}
	}
	return allTrue;
}

int getPickCountNeededForFourSuits(bool verbose)
{
	bool suitsPicked[]{ false, false, false, false }; // spades, hearts, diamonds, clubs
	int count{ 0 };

	int card{};
	Rank rank{};
	Suit suit{};

	
	while (!allArrayElementsAreTrue(suitsPicked, 4))
	{
		card = pickRandomCard();
		rank = getRank(card);
		suit = getSuit(card);
		count++;

		if (verbose)
		{
			std::cout << "Card " << count << ": "
				<< Constants::RANKS[static_cast<int>(rank)]
				<< " of "
				<< Constants::SUITS[static_cast<int>(suit)]
				<< '\n';
		}

		switch (suit)
		{
		case Suit::Spades:
			if (suitsPicked[0] == true) 
			{
				continue;
			}
			suitsPicked[0] = true;
			break;
		case Suit::Hearts:
			if (suitsPicked[1] == true)
			{
				continue;
			}
			suitsPicked[1] = true;
			break;
		case Suit::Diamonds:
			if (suitsPicked[2] == true)
			{
				continue;
			}
			suitsPicked[2] = true;
			break;
		case Suit::Clubs:
			if (suitsPicked[3] == true)
			{
				continue;
			}
			suitsPicked[3] = true;
			break;
		}

		if (!verbose)
		{
			std::cout << Constants::RANKS[static_cast<int>(rank)]
				<< " of "
				<< Constants::SUITS[static_cast<int>(suit)]
				<< '\n';
		}
		
	}

	return count;


}