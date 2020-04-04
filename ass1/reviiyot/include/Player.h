#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <list>
#include <vector>
#include <Hand.h>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Player : public Hand {
private:
  const string name;
  const int position;
  const int strategy;
  vector<Player*> *players;
  Deck *deckAccess;
        
public:
  Player(string s, int p, int strategyType,vector <Player*> *playersVector, Deck &deck);
  Player(const Player& c);
  Player& operator=(const Player& c);
  virtual ~Player();

  string getName();
  int getPosition();
  int getStrategy();
  int getNumOfPlayer();
  Player* getPlayerWithMostAmountOfCards();
  Player* getPlayerAtPosition(int position);
  string toString();
  void takeCardFromDeck(int countOfCard);
  void cardsMovement(string value, Player* player);
  bool isGameEnd(Player* player);
  string requestValueFromPlayer(string value, Player* player,bool &endGame);
  virtual string doStrategy(bool &endGame) = 0;
};

class PlayerType1 : public Player {
private:
  
public:
  PlayerType1(string name, int position,vector<Player*>* playersVector,Deck &deck);
  PlayerType1(const PlayerType1& c);
  PlayerType1& operator=(const PlayerType1& c);
  ~PlayerType1();
  string doStrategy(bool &endGame); 
};

class PlayerType2 : public Player {
public:
  PlayerType2(string name, int position,vector<Player*>* playersVector,Deck &deck);
  PlayerType2(const PlayerType2& c);
  PlayerType2& operator=(const PlayerType2& c);
  ~PlayerType2();
  string doStrategy(bool &endGame);
};

class PlayerType3 : public Player {
private:
  int nextAskedPlayer;
public:
    PlayerType3(string s, int p,vector<Player*>* playersVector,Deck &deck);
    PlayerType3(const PlayerType3& c);
    PlayerType3& operator=(const PlayerType3& c);
    ~PlayerType3();
    string doStrategy(bool &endGame);
};

class PlayerType4 : public Player {
private:
  int nextAskedPlayer;
public:
  PlayerType4(string s, int p,vector<Player*>* playersVector,Deck &deck);
  PlayerType4(const PlayerType4& c);
  PlayerType4& operator=(const PlayerType4& c);
  ~PlayerType4();
  string doStrategy(bool &endGame); 
};

#endif
