#pragma once
enum class Suit{}; // this will need to be filled out

enum class Rank{}; // this will need to be filled out

namespace Constants {
	constexpr int CARD_COUNT{ 52 }; // the # of cards in a deck
	constexpr int NUM_RANKS{ 13 };  // the # of ranks in a deck (two - ace)
	constexpr int NUM_SUITS{ 4 };   // the # of suits in a deck (hearts, clubs, etc.)

	// These string arrays will simplify the task of printing out the card values.
	// We don’t need to use a switch statement to find the string representation
	// of an enum. We can cast the enum as an int to index these arrays.

	// const std::string SUITS[] {}; // initialize & match with enums
	// const std::string RANKS[] {}; // initialize & match with enums

}

int pickRandomCard();