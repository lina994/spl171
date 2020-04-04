#include "Card.h"

/*
 * a single playing card. This class is abstract and holds the shape of the card only.
 */

// Constructor
Card::Card(Shape s) 
    : shape(s) {
}

// Copy Constructor
Card::Card(const Card& c) 
    : shape(c.shape) {
}

// Copy assignment operator
Card& Card::operator=(const Card& c) {
  if (this != &c) shape = c.shape;
  return *this;
}

// Destructor
Card::~Card() {
}

// Return card shape(Club,Diamond,Heart,Spade)
Shape Card::getShape() {
  return shape;
}

std::string Card::shapeToString(Shape s) {
  if (s == Club) return "C";
  if (s == Diamond) return "D";
  if (s == Heart) return "H";
  if (s == Spade) return "S";
  std::cout << "Illigal shape" << std::endl;
  return "Illigal shape";
}

// C < D < H < S
int Card::shapeNumericalValue(Shape s) {
  if (s == Club) return 1;
  if (s == Diamond) return 2;
  if (s == Heart) return 3;
  if (s == Spade) return 4;
  return 0;
}

// C < D < H < S
int Card::compareCardShape(Card& c) {
  int n1 = shapeNumericalValue(this->getShape());
  int n2 = shapeNumericalValue(c.getShape());
  if (n1 < n2) return -1;
  else if (n1 > n2) return 1;
  else return 0;
}

