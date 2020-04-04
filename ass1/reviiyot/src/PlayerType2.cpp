#include <iostream>
#include <list>
#include <Hand.h>
#include "Card.h"
#include <string>
#include "Player.h"

PlayerType2::PlayerType2(string name, int position,vector<Player*>* playersVector,Deck &deck)
    : Player(name,position,2, playersVector,deck) {
}

// Copy Constructor
PlayerType2::PlayerType2(const PlayerType2& c)
    : Player(c) {
}  

// Copy assignment operator
PlayerType2& PlayerType2::operator=(const PlayerType2& c) {
  if (this!=&c) {
    Player::operator=(c);
  }
  return *this;
}

// Destructor
PlayerType2::~PlayerType2() {
}

/*
 * PlayerType2: Requests the value he has the least from the player with most cards at hand. 
 * In case he has two or more values with the lowest amount, choose the lower value. 
 * In case two players have the most amount of cards, choose the one with higher position.
 * Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: 2.
 */
string PlayerType2::doStrategy(bool &endGame) {
  string value = leastCommonValueCard()->getValue();
  Player* player = getPlayerWithMostAmountOfCards();
  return requestValueFromPlayer(value, player, endGame);
}
