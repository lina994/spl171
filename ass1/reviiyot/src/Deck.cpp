#include "Deck.h"

/*
 * Total cards per game: (N+3)*4 cards (N>=1)
 * The values are: 2,3,4,...,N, Jack, Queen, King and Ace.
 */

// Constructor
Deck::Deck()
    : deck(new list <Card*>) {
}

// Copy Constructor
Deck::Deck(const Deck &obj) 
    : deck(obj.getCopyOfAllCard()) {
}

// Copy assignment operator
Deck& Deck::operator=(const Deck &other) {
  if (this != &other) {
    for (list<Card*>::iterator it=deck->begin(); it!=deck->end(); it++) {
      delete *it;
    }
    deck->clear();
    delete deck;
    deck = other.getCopyOfAllCard();
  }
  return *this;
}

// Destructor
Deck::~Deck() {
  if (deck != 0) {
    for (list<Card*>::iterator it = deck->begin(); it != deck->end(); it++){
      delete *it;
    }
  }
  deck->clear();
  delete deck;
  deck = 0;
}

void Deck::insertCard(Card* card) {
  deck->push_back(card);
}

// Returns the top card of the deck and remove it from the deck
Card* Deck::fetchCard() {
  Card* top = deck->front();
  deck->pop_front();
  return top;
}

// Get the number of cards in the deck
int Deck::getNumberOfCards() { 
  return deck -> size();
}

// Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
std::string Deck:: toString() {  
  string s("");
  for (std::list<Card*>::iterator it=deck->begin(); it!=deck->end(); it++){
    if (it!=deck->begin())
      s += " ";
    s += (*it)->toString();
  }
  return s;
}

// return deep copy of deck
list <Card*>* Deck::getCopyOfAllCard() const {
  list <Card*>* deckCopy = new list <Card*>;
  for (list<Card*>::const_iterator it=deck->begin(); it!=deck->end(); it++) {
    if ((*it)->getCardType() == "FigureCard") {
      FigureCard* fCard = (FigureCard*)*it;
      deckCopy->push_back(new FigureCard(*fCard));

    }
    else if ((*it) -> getCardType() == "NumericCard") {
      NumericCard* nCard = (NumericCard*)*it;
      deckCopy->push_back(new NumericCard(*nCard));
    }
  }
  return deckCopy;
}

