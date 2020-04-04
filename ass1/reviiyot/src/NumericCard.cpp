#include "Card.h"

/*
 * Inherits from Card. Used for cards with numeric values. 
 * (2, 3, 4, 5, etc...)
 */

// Constructor
NumericCard::NumericCard(Shape s, int n) 
    : Card(s),
      number(n) {
}

// Copy Constructor
NumericCard::NumericCard(const NumericCard& c) 
    : Card(c),
      number(c.number) {
} 

// Copy assignment operator
NumericCard& NumericCard::operator=(const NumericCard& c) {
  if (this != &c){
    Card::operator=(c);
    number = c.number;
  }
  return *this;   
}

// Destructor
NumericCard::~NumericCard() {
}

int NumericCard::compareNumericCards(NumericCard& c) {
  if (this->number < c.number) return -1;
  if (this->number > c.number) return 1;
  return 0;
}

string NumericCard::getCardType() {  
  return "NumericCard";
}

string NumericCard::getValue() {
  return to_string(number);
}

// Returns the string representation of the card "<value><shape>".
string NumericCard::toString() {     
  string shape = shapeToString(getShape());
  string num = getValue();
  return num + shape;
}


