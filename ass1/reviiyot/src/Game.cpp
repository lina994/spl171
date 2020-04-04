#include <iostream>
#include <fstream>
#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include <string>
#include <sstream>


// Verbal: 0 or 1.
void Game::readVerbalValue(fstream &myfile) {
  string line;
  while (getline (myfile,line)) {
    // skip empty lines and comments
    if(line == "" || line.at(0)=='#' || line.at(0)=='\\')
      continue;
    verbal = line.at(0)=='1';
    break;
  }
}

// N – Highest numeric value. indicates only figures no numeric values.
void Game::readHighestNumericValue(fstream &myfile) {
  string line;
  while (getline (myfile,line)) {
    // skip empty lines and comments
    if(line == "" || line.at(0)=='#' || line.at(0)=='\\')
      continue;
    // stoi parses str interpreting its content as an integral number
    highNumericValue = stoi(line); 
    break;
  }
}

bool Game::isNumber(string &s) {
  for(string::iterator it = s.begin(); it != s.end(); it++) {
    if (!isdigit(*it))
      return false;
  }
  return !s.empty();
}

// return true if its deck line and false if its player line
bool Game::isDeckLine(string &s){
  // find first ' ' char.
  size_t i = s.find(' ');
  if (i == string::npos)
    return true; // player line should include space char
  i++;
  // check if after ' ' there are only digits.
  string subStr = s.substr(i,s.size());
  return !isNumber(subStr); // each card include letters(represent figure)
}

bool Game::isFigureChar(char c) {
  return c =='J' || c =='Q' || c =='K' || c =='A';
}

Figure Game::charToFigure(char c) {
  if(c == 'J') return Jack;
  else if(c == 'Q') return Queen;
  else if(c == 'K') return King;
  return Ace;
}

bool Game::isShapeChar(char c) {
  return c =='C' || c =='D' || c =='H' || c =='S';
}

Shape Game::charToShape(char c) {
  if(c == 'C') return Club;
  else if(c == 'D') return Diamond;
  else if(c == 'H') return Heart;
  return Spade; // c == 'S'
}

Card* Game::createFigureCard(string s){
  Figure figure = charToFigure(s.at(0));
  Shape shape = charToShape(s.at(1));
  return new FigureCard(shape, figure);
}

int Game::charToInt(char c) {
  return c - '0';
}

Card* Game::createNumericCard(string s) {
  Shape shape;
  int value = 0;
  unsigned int k = 0;
  char a;
  while(k < s.size()){    
    a = s.at(k);
    if(isShapeChar(a)) {
      shape = charToShape(a);
      break;
    }
    value = value * 10 + charToInt(a);  
    k++;
  }
  return new NumericCard(shape,value);
}

Card* Game::createCard(string s){
  if(isFigureChar(s.at(0))){
    return createFigureCard(s);
  }
  return createNumericCard(s);
}

// Initial deck ordered from top to bottom.
void Game::readDeckCards(fstream &myfile, string &line) {
  while (getline (myfile,line)) {
    // skip empty lines and comments
    if(line == "" || line.at(0)=='#' || line.at(0)=='\\')
      continue;

    if(isDeckLine(line)) {
      string buf;  // Have a buffer string
      stringstream ss(line);  // breaking string into word using stringstream 
      while (ss >> buf) {     // read word from the stringstream
        deck.insertCard(createCard(buf));
      }
    }
    else break;
  }
}

Player* Game::createPlayer(string s){
  size_t i = s.find(' ');  // find first ' ' char.
  string name = s.substr(0,i);
  int strategy = std::stoi(s.substr(i+1));
  
  if(strategy == 1){
    return new PlayerType1(name, players.size(), &players, deck);
  }
  else if(strategy == 2){
    return new PlayerType2(name, players.size(), &players, deck);
  }
  else if(strategy == 3){
    return new PlayerType3(name, players.size(), &players, deck);
  }
  else{
    return new PlayerType4(name, players.size(), &players, deck);
  }
}

void Game::readPlayers(fstream &myfile, string &line) {
  do {
    // skip empty lines and comments
    if(line == "" || line.at(0)=='#' || line.at(0)=='\\')
      continue;
    players.push_back(createPlayer(line));

  } while(getline (myfile,line));
}


void Game::parseConfigurationFile(char* configurationFile) {
  string line;
  fstream  myfile;
  myfile.open(configurationFile, ios::in );
  readVerbalValue(myfile);
  readHighestNumericValue(myfile);
  readDeckCards(myfile, line);
  readPlayers(myfile, line);
  myfile.close();
}

void Game::copyPlayersVector(const vector<Player *>* cPlayers) {
  Player* cPlayer;
  Player* copy;
  for (std::vector<Player*>::const_iterator it=cPlayers->begin(); it!=cPlayers->end() ; it++) {
    cPlayer = *it;
    if(cPlayer->getStrategy() == 1)
      copy = new PlayerType1(*((PlayerType1*)cPlayer));
    else if(cPlayer->getStrategy() == 2)
      copy = new PlayerType2(*((PlayerType2*)cPlayer));
    else if(cPlayer->getStrategy() == 3)
      copy = new PlayerType3(*((PlayerType3*)cPlayer));
    else if(cPlayer->getStrategy() == 4) 
      copy = new PlayerType4(*((PlayerType4*)cPlayer));
    players.push_back(copy);
  }
}

void Game::copyTurnList(const list <string>* turns) {
  for (list<string>::const_iterator it = turns->begin(); it != turns->end(); it++) {
    turnList.push_back(*it);
  }
}

// Constructor
Game::Game(char* configurationFile)
    : players(),
      deck(), 
      turnList() {
  parseConfigurationFile(configurationFile);
}

// Copy Constructor
Game::Game(const Game& c) : 
    players(), 
    deck(c.deck),
    verbal(c.verbal),
    highNumericValue(c.highNumericValue), 
    turnList(), 
    endGame(c.endGame),
    numberOfTurns(c.numberOfTurns) {
  copyPlayersVector(&c.players);
  copyTurnList(&c.turnList);
}

// Copy assignment operator
Game& Game::operator=(const Game& c){
  if (this != &c) {
    deck = c.deck;
    verbal = c.verbal;
    highNumericValue = c.highNumericValue;
    endGame = c.endGame;
    numberOfTurns = c.numberOfTurns;

    for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++)
      delete *it;
    players.clear();
    copyPlayersVector(&c.players);
    turnList.clear();
    copyTurnList(&c.turnList);
  }
  return *this;
}

// Destructor
Game::~Game() {
  for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++)
    delete *it;
  players.clear();
  turnList.clear();
}

void Game::init(){ 
  for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++)
    (*it)->takeCardFromDeck(7);
}

void Game::pushCurrentStateToList() {
  string temp;
  temp = "Turn " + to_string(numberOfTurns);
  turnList.push_back(temp);
  temp = "Deck: " + deck.toString();
  turnList.push_back(temp);
  for (vector<Player*>::iterator it2=players.begin(); it2!=players.end(); it2++){
      temp = (*it2)-> toString();
      turnList.push_back(temp);
  }
}

void Game::pushTurnDetailsToList(string &s) {
  turnList.push_back(s);
  turnList.push_back("");
}

void Game::playTurn(Player* p) {
  string info;
  numberOfTurns++;
  if(verbal)
    pushCurrentStateToList();
  info = p->doStrategy(endGame);
  if(verbal)
    pushTurnDetailsToList(info);
}

void Game::play() {
  for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++)
    (*it)->discardsAllSets();

  while(!endGame) {
    for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++) {
      if (endGame)
        break;
      playTurn(*it);
    }
  }
}

void Game::printState() {
  cout << "Deck: " << deck.toString() << endl;
  for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++)
    cout << (*it)->toString() << endl;
}

void Game::printAllTurns() {
  for (list<string>::iterator it=turnList.begin(); it!=turnList.end(); it++)
    cout << *it << endl;
}

void Game::collectAllWinners(list<Player*> &winners) {
  for (vector<Player*>::iterator it=players.begin(); it!=players.end(); it++) {
    if ((*it)->getNumberOfCards() == 0) {
      winners.push_back(*it);
    }
  }
}

void Game:: printWinner() {
  if(verbal)
    printAllTurns();

  list<Player*> winners;
  collectAllWinners(winners);
  if (winners.size() == 1)            
    cout << "***** The Winner is: " << winners.front()->getName() << " *****" << endl;
  else 
    cout << "***** The winners are: " << winners.front()->getName() << " and " << winners.back()->getName() << " *****" << endl;
}    

void Game::printNumberOfTurns(){
  cout << "Number of turns: " << numberOfTurns << endl;
}



