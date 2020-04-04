#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <string>
#include <list>

#include "Card.h"

using namespace std;

class Hand {
private:
  list <Card*> hand;  // sorted list
public:
  Hand();                               // Constructor
  Hand(const Hand &obj);                // Copy Constructor
  Hand& operator= (const Hand &other);  // Copy assignment operator
  virtual ~Hand();                      // Destructor

  bool contains(Card &card);
  int compareCardValue(Card& c1 , Card& c2);
  int compareCard(Card& c1, Card& c2);
  bool addCard(Card &card);
  bool removeCard(Card &card);
  int getNumberOfCards();
  string toString();
  Card* leastCommonValueCard();
  Card* mostCommonValueCard();
  Card* getHighestValueCard();
  Card* getLowertValueCard();
  void discardsAllSets();
  void discardsCards(string value);
  list <Card*> extractListOfCards(string value); // remove card from hand and return list of this card
  void addListOfCard(list <Card*> list);
  list <Card*> getCopyOfAllCard() const; // 
};

#endif
