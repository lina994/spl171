#include <iostream>
#include <Hand.h>
#include <string>
#include <list>
#include <vector>
#include <Player.h>

// Constructor
Player::Player(string pName, int pPosition,int strategyType, vector<Player*> *playersVector,Deck &deck) 
    : Hand(), 
      name(pName),
      position(pPosition),
      strategy(strategyType), 
      players(playersVector),
      deckAccess(&deck) {
}

// Copy Constructor TODO
Player::Player(const Player& c)
    : Hand(c),
      name(c.name),
      position(c.position),
      strategy(c.strategy),
      players(c.players),
      deckAccess(c.deckAccess) {
}  

// Copy assignment operator TODO
Player& Player::operator=(const Player& c) {
  if (this!=&c) {
    Hand::operator=(c);
    // name, position, strategy are const fields
    players = c.players;
    deckAccess = c.deckAccess;
  }
  return *this;
}

// Destructor
Player::~Player() {
  players = 0;
  deckAccess = 0;
}

string Player::getName() {
  return name;
}

int Player::getPosition() {
  return position;
}

int Player::getStrategy() {
  return strategy;
}

int Player::getNumOfPlayer() {
  return players->size();
}

// Return a player with most cards at hand. (except current player)
// In case two players have the most amount of cards, choose the one with the higher position.
Player* Player:: getPlayerWithMostAmountOfCards() {
  Player* playerWithMostCards;
  int maxNumOfCards = 0;
  for (vector<Player*>::iterator it=players->begin(); it!=players->end(); it++) {
    if((*it)->getNumberOfCards() >= maxNumOfCards) {  
      if ((*it)->getPosition() != this->getPosition()) {
        playerWithMostCards = *it;
        maxNumOfCards = (*it)->getNumberOfCards();
      }  
    }        
  }   
  return playerWithMostCards;
}

Player* Player:: getPlayerAtPosition(int position) {
  for (std::vector<Player*>::iterator it=players->begin(); it!=players->end() ; it++) {
    if((*it)->getPosition() == position) {
      return *it;
    }
  }
  std::cout << "player with this position not found" << std::endl;
  return this;
}

string Player::toString() {
  return getName() + ": " + Hand::toString();
}

void Player::takeCardFromDeck(int countOfCard) {
  int i = 0;
  while(i < countOfCard && deckAccess->getNumberOfCards() > 0) {
    addCard(*(deckAccess->fetchCard()));
    i++;
  }
}

/*
 * If the asked player holds K(>0) cards of that value he/she has to give all of his/her cards
 * of that value to the asking player and draw K new cards from the top of the deck. 
 * If the asked player doesn't have any card of that value the asking player picks up one card 
 * from the top of the deck.
 */
void Player::cardsMovement(string value, Player* player) {
  list <Card*> cards = player->extractListOfCards(value);
  int numCard = cards.size();
  if(numCard > 0) {
    addListOfCard(cards);
    if (player->getNumberOfCards() != 0)
      player->takeCardFromDeck(numCard);
  }
  else {
    takeCardFromDeck(1);
  }
}

bool Player::isGameEnd(Player* player) {
  if(getNumberOfCards() == 0)
    return true;
  else if(player->getNumberOfCards() == 0)
    return true;
  return false;
}

string Player::requestValueFromPlayer(string value, Player* player,bool &endGame) {
  cardsMovement(value, player);
  discardsAllSets();
  player->discardsAllSets();
  endGame = isGameEnd(player);
  string s = getName() + " asked " + player->getName() + " for the value " + value;
  return s;
}