#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
  vector<Player *> players;  // The list of the players
  Deck deck;                 // The deck of the game
  bool verbal = false;       // Should intermediate results be printed? Received from the configuration file
  int highNumericValue = 0;  // Received from the configuration file
  list <string> turnList;
  bool endGame = false;
  int numberOfTurns = 0;  // turns counter

  // private functions of file parser
  void readVerbalValue(fstream &myfile);
  void readHighestNumericValue(fstream &myfile);
  bool isNumber(string &s);
  bool isDeckLine(string &s);
  bool isFigureChar(char c);
  Figure charToFigure(char c);
  bool isShapeChar(char c);
  Shape charToShape(char c);
  Card* createFigureCard(string s);
  int charToInt(char c);
  Card* createNumericCard(string s);
  Card* createCard(string s);  
  void readDeckCards(fstream &myfile, string &line);
  Player* createPlayer(string s);
  void readPlayers(fstream &myfile, string &line);
  void parseConfigurationFile(char* configurationFile);  

  // private functions of copy constructor
  void copyPlayersVector(const vector<Player *>* cPlayers);
  void copyTurnList(const list <string>* turnList);

  // private functions of play
  void pushCurrentStateToList();
  void pushTurnDetailsToList(string &s);
  void playTurn(Player* p);

  // other
  void printAllTurns();
  void collectAllWinners(list<Player*> &winners);


public:  
  Game(char* configurationFile);
  Game(const Game& c);
  Game& operator=(const Game& c);
  ~Game();

  void init();
  void play();
  void printState();         // Print the state of the game as described in the assignment.
  void printWinner();        // Print the winner of the game as describe in the assignment.
  void printNumberOfTurns(); // Print the number of played turns at any given time.  
};

#endif
