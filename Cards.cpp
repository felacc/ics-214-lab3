#include <cstdlib>
#include <iostream>
#include <random>
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
	

	int* randomizedDeck{ nullptr }; // don't initialize if never used

	// if no replacement, get a shuffled array of cards
	if (!replacement)
	{
		randomizedDeck = new int[Constants::CARD_COUNT];
		// fill deck
		for (int i = 0; i < Constants::CARD_COUNT; i++)
		{
			randomizedDeck[i] = i;
		}
		// magic required for std::shuffle
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(randomizedDeck, randomizedDeck + Constants::CARD_COUNT, g); // using memory addresses of array beginning and end
	}

	bool suitsPicked[static_cast<int>(Suit::count)]{}; // 0->3: spades, hearts, diamonds, clubs
	int count{ 0 };
	int card{};
	Suit suit{};

	while (!allArrayElementsAreTrue(suitsPicked, static_cast<int>(Suit::count)))
	{
		if (!replacement)
		{
			card = randomizedDeck[count];
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