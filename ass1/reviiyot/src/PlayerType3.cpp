#include <iostream>
#include <list>
#include <Hand.h>
#include "Card.h"
#include <string>
#include "Player.h"
 
PlayerType3::PlayerType3(string name, int position,vector<Player*>* playersVector,Deck &deck)
    : Player(name,position,3, playersVector,deck),
      nextAskedPlayer(0) {
  if (position == 0) nextAskedPlayer++;
}

// Copy Constructor
PlayerType3::PlayerType3(const PlayerType3& c)
    : Player(c),
      nextAskedPlayer(c.nextAskedPlayer) {
}  

// Copy assignment operator
PlayerType3& PlayerType3::operator=(const PlayerType3& c) {
  if (this!=&c) {
    Player::operator=(c);
    nextAskedPlayer = c.nextAskedPlayer;
  }
  return *this;
}

// Destructor
PlayerType3::~PlayerType3() {
}

/*
 * Start from the first player (except for oneself), move to the next one at
 * each turn in a cyclic order. 
 * The player requests for the highest value he/she has at hand.
 * Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: K.
 */
string PlayerType3::doStrategy(bool &endGame) {
  string value = getHighestValueCard()->getValue();
  Player* player = getPlayerAtPosition(nextAskedPlayer);

  // update nextAsk
  nextAskedPlayer = (nextAskedPlayer + 1) % getNumOfPlayer();
  if (nextAskedPlayer == getPosition())
    nextAskedPlayer = (nextAskedPlayer + 1) % getNumOfPlayer();
  
  return requestValueFromPlayer(value, player, endGame);
}

