#pragma once
#include <string>

enum class Suit
{
	Spades,      // 0
	Hearts,      // 1
	Diamonds,    // 2
	Clubs,       // 3

	count        // 4
}; 

enum class Rank
{
	Ace,      // 0
	Two,      // 1
	Three,    // 2
	Four,     // 3
	Five,     // 4
	Six,      // 5
	Seven,    // 6
	Eight,    // 7
	Nine,     // 8
	Ten,      // 9
	Jack,     // 10
	Queen,    // 11
	King,     // 12

	count     // 13

}; 

namespace Constants {
	constexpr int CARD_COUNT{ 52 }; // the # of cards in a deck
	constexpr int NUM_RANKS{ 13 };  // the # of ranks in a deck (two - ace)
	constexpr int NUM_SUITS{ 4 };   // the # of suits in a deck (hearts, clubs, etc.)

	const std::string SUITS[] 
	{
		"Spades",
		"Hearts",
		"Diamonds",
		"Clubs"
	}; 

	const std::string RANKS[] 
	{
		"Ace",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten",
		"Jack",
		"Queen",
		"King"
	};

}

/// <summary>
///	Pick a random card from the deck.
/// </summary>
/// <returns>A random card index represented by the values [0,51]</returns>
int pickRandomCard();

/// <summary>
/// Get the rank of a specific card index.
/// </summary>
/// <param name="index">Card index from [0, 51].</param>
/// <returns>An enum [0, 12] representing card rank.</returns>
Rank getRank(int index);

/// <summary>
/// Get the suit of a specific card index.
/// </summary>
/// <param name="index">Card index from [0, 51].</param>
/// <returns>An enum [0, 3] representing card suit.</returns>
Suit getSuit(int index);

/// <summary>
/// Assesses whether all elements in a boolean array are true.
/// </summary>
/// <param name="elements">Boolean array of values.</param>
/// <param name="size">Size of array.</param>
/// <returns>True if all the values in elements are true, false otherwise.</returns>
bool allArrayElementsAreTrue(bool elements[], int size);

/// <summary>
/// "Pulls" random cards until it gets one of each suit.
/// </summary>
/// <param name="verbose">
/// When true, output all picked cards and count. 
/// When false, only print first card picked of each suit.
/// </param>
/// <returns>Number of cards picked before all four suits were found.</returns>
int getPickCountNeededForFourSuits(bool verbose = true);