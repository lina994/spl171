#include <iostream>
#include <list>
#include <Hand.h>
#include "Card.h"
#include <string>
#include "Player.h"

PlayerType4::PlayerType4(string name, int position,vector<Player*>* playersVector,Deck &deck)
    : Player(name,position,4, playersVector,deck),
      nextAskedPlayer(0) {
  if (position == 0) nextAskedPlayer++;
}

// Copy Constructor
PlayerType4::PlayerType4(const PlayerType4& c)
    : Player(c),
      nextAskedPlayer(c.nextAskedPlayer) {
}  

// Copy assignment operator
PlayerType4& PlayerType4::operator=(const PlayerType4& c) {
  if (this!=&c) {
    Player::operator=(c);
    nextAskedPlayer = c.nextAskedPlayer;
  }
  return *this;
}

// Destructor
PlayerType4::~PlayerType4() {
}

/*
 * Start from the first player (except for oneself), move to the next one at
 * each turn in a cyclic order. 
 * The player requests for the lowest value he/she has at hand.
 * Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: 2.
 */
string PlayerType4::doStrategy(bool &endGame) {
  string value = getLowertValueCard()->getValue();
  Player* player = getPlayerAtPosition(nextAskedPlayer);

  // update nextAsk
  nextAskedPlayer = (nextAskedPlayer + 1) % getNumOfPlayer(); 
  if (nextAskedPlayer == getPosition())
    nextAskedPlayer = (nextAskedPlayer + 1) % getNumOfPlayer();

  return requestValueFromPlayer(value, player, endGame);
}