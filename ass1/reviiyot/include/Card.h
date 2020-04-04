#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

enum Shape {
  Club,
  Diamond,
  Heart,
  Spade
};

enum Figure {
  Jack,
  Queen,
  King,
  Ace
};

class Card {
private:
  Shape shape;
  int shapeNumericalValue(Shape s);

public:
  Card(Shape s);                   // Constructor
  Card(const Card& c);             // Copy Constructor
  Card& operator=(const Card& c);  // Copy assignment operator
  virtual ~Card();                 // Destructor

  Shape getShape();
  string shapeToString(Shape s);
  int compareCardShape(Card& c);
  virtual string getCardType() = 0;
  virtual string getValue() = 0;
  virtual string toString() = 0;  // Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
};


class FigureCard : public Card {
private:
  Figure figure;
public:
  FigureCard(Shape s, Figure f);
  FigureCard(const FigureCard &c);
  FigureCard& operator=(const FigureCard& c);
  ~FigureCard();

  int figureNumericalValue();
  int compareFigureCards(FigureCard& c);
  virtual string getCardType() override;
  virtual string getValue() override;  // TODO
  virtual string toString() override;
};


class NumericCard : public Card {
private:
  int number;
public:
  NumericCard(Shape s, int n);
  NumericCard(const NumericCard &c);
  NumericCard& operator=(const NumericCard& c);
  ~NumericCard();
  
  int compareNumericCards(NumericCard& c);
  virtual string getCardType() override;
  virtual string getValue() override;  // TODO
  virtual string toString() override;
};

#endif
