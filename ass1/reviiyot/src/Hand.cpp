#include "Hand.h"
#include <list>
#include <string>


// Constructor
Hand::Hand()
    : hand() {
}

// Copy Constructor
Hand::Hand(const Hand &obj)
    : hand(obj.getCopyOfAllCard()) {
}

// Copy assignment operator
Hand& Hand::operator= (const Hand &obj) {
  if (this != &obj) {
    for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
      delete *it;
    }
    hand.clear();
    hand = obj.getCopyOfAllCard();
  }
  return *this;
}

// Destructor
Hand::~Hand() {
  for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
    delete *it;
  }
  hand.clear();
}

// used for checking the card existence in the given Hand.
// returns true if the card is found in the Hand else it gives false.
bool Hand:: contains(Card &card){
  for (list<Card*>::iterator it=hand.begin(); it!=hand.end() ; it++){
    if(card.toString() == (*it)->toString()) return true;
  }
  return false;
}

int Hand::compareCardValue(Card& c1, Card& c2) {
  if (c1.getCardType() == "FigureCard") {
    if (c2.getCardType() == "NumericCard") {
      return 1;
    }
    else if (c2.getCardType() == "FigureCard") {
      return ((FigureCard&)c1).compareFigureCards((FigureCard&)c2);
    }
  }
  else if (c1.getCardType() == "NumericCard") {
    if (c2.getCardType() == "FigureCard") {
      return -1;
    } 
    else if (c2.getCardType() == "NumericCard") {
      return ((NumericCard&)c1).compareNumericCards((NumericCard&)c2);
    }
  }
  return 0;
}

// “value” is the most significant value while “shape” is the least significant value.
int Hand::compareCard(Card& c1, Card& c2) {
  int ans = compareCardValue(c1, c2);
  if (ans != 0) return ans;
  else return c1.compareCardShape(c2);
}

// add card to hand, preserve hand order
bool Hand:: addCard(Card &card) {
  for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
    if (card.toString() == (*it)->toString()) { // card already exist
      return false;
    }
    if (compareCard((*(*it)), card) == 1) { // card < it
      hand.insert(it, &card);
      return true;
    }
  }
  hand.push_back(&card);
  return true; 
}

bool Hand::removeCard(Card &card) {
  if(!this->contains(card)) {
    return false;
  }
  hand.remove(&card);
  return true;
}

// Get the number of cards in hand;
int Hand::getNumberOfCards() {   
  return hand.size();
}

// Return a list of the cards, separated by space, in one line,in a sorted order, ex: "2S 5D 10H"
string Hand:: toString() {
  string s("");
  for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
    if (it!=hand.begin())
      s += " ";
    s += (*it)->toString();
  }
  return s;
}

// return the card with least common value 
// In case he has two or more values with the lowest amount, choose the lower value.
// assumption: hand is sorted, non empty
Card* Hand::leastCommonValueCard() {
  Card* rarestValueCard;
  int rarestValueCount = getNumberOfCards() + 1;
  Card* currentValueCard;
  int currentValueCount = getNumberOfCards() + 1;
  string currentValue = "none";

  for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
    if((*it)->getValue() == currentValue) {  // the same value
      currentValueCount++;
    }
    else { // card with different value
      if(currentValueCount < rarestValueCount) { // least common value found
        rarestValueCard = currentValueCard;
        rarestValueCount = currentValueCount;
      }
      currentValueCard = *it;
      currentValueCount = 1;
      currentValue = (*it)->getValue();
    }
  }
  if(currentValueCount < rarestValueCount) { // least common value found
    rarestValueCard = currentValueCard;
  }
  return rarestValueCard;
}

// return the card with most common value 
// In case he has two or more values with the same highest amount, choose the higher value.
// assumption: hand is sorted, non empty
Card* Hand::mostCommonValueCard() {
  Card* mostCommonValue;
  int mostCommonValueCount = 0;
  Card* currentValueCard;
  int currentValueCount = 0;
  string currentValue ="none";

  for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
    if((*it)->getValue() == currentValue) {  // the same value
      currentValueCount++;
    }
    else { // card with different value
      if(currentValueCount >= mostCommonValueCount) { // most common value found
        mostCommonValue = currentValueCard;
        mostCommonValueCount = currentValueCount;
      }
      currentValueCard = *it;
      currentValueCount = 1;
      currentValue = (*it)->getValue();
    }
  }
  if(currentValueCount >= mostCommonValueCount) { // most common value found
    mostCommonValue = currentValueCard;
  }
  return mostCommonValue;  
}

Card* Hand::getHighestValueCard() {
  return hand.back();
}

Card* Hand::getLowertValueCard() {
  return hand.front();
}

// set are 4 cards of a single value
void Hand::discardsAllSets() {
  int counter = 0;
  string value = "";
  for (list<Card*>::iterator it=hand.begin(); it!=hand.end(); it++) {
    if((*it)->getValue() != value) {
      counter = 1;
      value = (*it) -> getValue();
    }
    else{
      counter++;
      if(counter == 4) {
        discardsCards(value);
        return;
      }
    }
  }
}

// remove card from hand with given value.
void Hand::discardsCards(string value) { // if there are set of card, discard the set
  list<Card*>::iterator it = hand.begin();
  while (it != hand.end()) {
    if ((*it)->getValue() == value) {
      delete *it;
      hand.erase(it++);  // alternatively, i = items.erase(i);
    }
    else {
      ++it;
    }
  }
}

// remove cards from hand and return list of this cards
list <Card*> Hand::extractListOfCards(string value) {
  list <Card*> ans;
  list<Card*>::iterator it = hand.begin();
  while (it != hand.end()) {
    if ((*it)->getValue() == value) {
      ans.push_back(*it);
      hand.erase(it++);
    }
    else {
      ++it;
    }
  }
  return ans;
}

void Hand::addListOfCard(list <Card*> cards) {
  for (list<Card*>::iterator it=cards.begin(); it != cards.end(); it++) {
    addCard(**it);
  }
}

// return deep copy of Hand
list <Card*> Hand::getCopyOfAllCard() const {
  list <Card*> handCopy;
  for (list<Card*>::const_iterator it=hand.begin(); it!=hand.end(); it++) {
    if ((*it)->getCardType() == "FigureCard") {
      FigureCard* fCard = (FigureCard*)*it;
      handCopy.push_back(new FigureCard(*fCard));

    }
    else if ((*it) -> getCardType() == "NumericCard") {
      NumericCard* nCard = (NumericCard*)*it;
      handCopy.push_back(new NumericCard(*nCard));
    }
  }
  return handCopy;
}



