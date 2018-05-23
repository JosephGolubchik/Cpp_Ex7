#pragma once

#include "DummyPlayers.h"
#include "Champion.h"
#include <string>

class TicTacToe {
  
  Board* gameBoard;
  Board* finalBoard;
  bool player;
  bool gameWinner;
  string winnerName;
  bool finished = 0;
  
  
  public:
  void play(Player& pA, Player& pB);
  Board board() const;
  Player& winner() const;
  bool finished;
  bool checkRows();
  bool checkCol();
  bool checkMainDiag();
  bool checkOtherDiag();
  bool checkTie();
  bool isFull();
  bool checkWin();
  void initBoard();
  
  TicTacToe(int size){
    gameBoard = new Board{size};
    finalBoard = new Board{size};
    player = 0;
    finished = 0;
  }
  
  ~TicTacToe(){
    delete gameBoard;
    delete finalBoard;
  }

};


