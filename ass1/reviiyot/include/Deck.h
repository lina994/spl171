#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <list>
#include <string>
#include "Card.h"

using namespace std;

class Deck {
private:
  list <Card*>* deck;

public:
  Deck();                                // Constructor
  Deck(const Deck &obj);                 // Copy Constructor
  Deck& operator= (const Deck &other);   // Copy assignment operator
  ~Deck();                               // Destructor

  void insertCard(Card* card);
  Card* fetchCard();      // Returns the top card of the deck and remove it from the deck
  int getNumberOfCards(); // Get the number of cards in the deck
  string toString();      // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
  list <Card*>* getCopyOfAllCard() const; 
};

#endif
