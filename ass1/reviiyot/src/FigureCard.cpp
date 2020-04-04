#include "Card.h"

/*
 * Inherits from Card. Used for cards with a figure on. 
 * That is: Jack, Queen, King and Ace.
 */

// Constructor
FigureCard::FigureCard(Shape s, Figure f)
    : Card(s),
      figure(f) {
}

// Copy Constructor
FigureCard::FigureCard(const FigureCard& c) 
    : Card(c),
      figure(c.figure) { 
}

// Copy assignment operator
FigureCard& FigureCard::operator=(const FigureCard& c) {
  if (this != &c) {
    Card::operator=(c);
    figure = c.figure;
  }
  return *this;
}

// Destructor
FigureCard::~FigureCard() {
}

int FigureCard::figureNumericalValue() {
  if (figure == Jack) return 1;  // Jack
  if (figure == Queen) return 2; // Queen
  if (figure == King) return 3;  // King
  if (figure == Ace) return 4;   // Ace
  return 0;
}

int FigureCard::compareFigureCards(FigureCard& c) {
  if (this->figureNumericalValue() < c.figureNumericalValue()) return -1;
  if (this->figureNumericalValue() > c.figureNumericalValue()) return 1;
  return 0;
}

string FigureCard::getCardType() {  
  return "FigureCard";
}

string FigureCard::getValue() {
  if (figure == Jack) return "J";
  if (figure == Queen) return "Q";
  if (figure == King) return "K";
  if (figure == Ace) return "A";
  cout << "Illigall figure" << endl;
  return "Illigal figure";
}

// Returns the string representation of the card: "<value><shape>".
string FigureCard::toString() {  
  string shape = shapeToString(getShape());
  string figure = getValue();
  return figure + shape;
}





