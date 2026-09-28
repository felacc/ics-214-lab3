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

	// These string arrays will simplify the task of printing out the card values.
	// We don’t need to use a switch statement to find the string representation
	// of an enum. We can cast the enum as an int to index these arrays.

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

int pickRandomCard();

Rank getRank(int index);

Suit getSuit(int index);