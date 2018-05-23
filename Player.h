#pragma once
#include "Board.h"
#include <string>

class Player{
  
  public:
  string sName;
  char myChar;
  bool firstMove = false;
  
  virtual const string name() const;
  virtual const Coordinate play(const Board& board) = 0;
  char getChar();
  void setChar(char myChar);
  
  Player(){
    sName = "Player";
    myChar = '.';
  }

};


