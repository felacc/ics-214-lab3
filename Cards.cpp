#include <cstdlib>
#include <iostream>	
#include "Cards.h"

int pickRandomCard()
{
	return rand() % Constants::CARD_COUNT;
}

Rank getRank(int index)
{
	Rank rank{ index % static_cast<int>(Rank::count) }; // returns an int from 0-12 used to select rank

	return rank;

}


Suit getSuit(int index)
{
	Suit suit{ index / static_cast<int>(Rank::count) };// returns an int from 0-3 used to select suit

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

int getPickCountNeededForFourSuits(bool verbose, bool replacement)
{
	

	bool pickedCards[Constants::CARD_COUNT]{};

	bool suitsPicked[static_cast<int>(Suit::count)]{}; // 0->3: spades, hearts, diamonds, clubs
	int count{ 0 };
	int card{};
	Suit suit{};

	while (!allArrayElementsAreTrue(suitsPicked, static_cast<int>(Suit::count)))
	{
		
		
		

		if (!replacement)
		{
			do
			{
				card = pickRandomCard();
			} while (pickedCards[card] == true);
			pickedCards[card] = true;
		} 
		else
		{
			card = pickRandomCard();
		}

		suit = getSuit(card);
		int intSuit = static_cast<int>(suit);
		count++;

		if (!suitsPicked[intSuit])
		{
			suitsPicked[intSuit] = true;
		}

		if (verbose)
		{
			Rank rank = getRank(card);
			std::cout << Constants::RANKS[static_cast<int>(rank)]
				<< " of "
				<< Constants::SUITS[intSuit]
				<< '\n';
		}
		
	}

	return count;


}