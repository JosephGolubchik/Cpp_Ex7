#pragma once

#include "DummyPlayers.h"
#include "Champion.h"
#include <string>

class TicTacToe {
  
  Board* gameBoard;
  bool finished;
  bool player;
  bool gameWinner;
  string winnerName;
  
  
  public:
  void play(Player& pA, Player& pB);
  Board board() const;
  Player& winner() const;
  bool checkRows();
  bool checkCol();
  bool checkMainDiag();
  bool checkOtherDiag();
  bool checkTie();
  bool isFull();
  bool checkWin();
  
  TicTacToe(int size){
    gameBoard = new Board{size};
    player = 0;
    gameWinner = 1;
  }
  
  ~TicTacToe(){
    delete gameBoard;
  }

};


