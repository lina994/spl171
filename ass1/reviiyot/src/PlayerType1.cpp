#include <iostream>
#include <list>
#include <Hand.h>
#include "Card.h"
#include <string>
#include "Player.h"

// Constructor
PlayerType1::PlayerType1(string name, int position,vector<Player*>* playersVector,Deck &deck)
    : Player(name,position,1, playersVector,deck) {
}

// Copy Constructor
PlayerType1::PlayerType1(const PlayerType1& c)
    : Player(c) {
}  

// Copy assignment operator
PlayerType1& PlayerType1::operator=(const PlayerType1& c) {
  if (this!=&c) {
    Player::operator=(c);
  }
  return *this;
}

// Destructor
PlayerType1::~PlayerType1() {
}

/*
 * Requests the value he has the most from the player with most cards at hand. 
 * In case he has two or more values with the same highest amount, choose the higher value. 
 * In case two players have the most amount of cards, choose the one with the higher position.
 * Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: 6.
 */
string PlayerType1::doStrategy(bool &endGame) {
  string value = mostCommonValueCard()->getValue();
  Player* player = getPlayerWithMostAmountOfCards();
  return requestValueFromPlayer(value, player, endGame);
}

