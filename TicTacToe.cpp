#include "TicTacToe.h"

void TicTacToe::play(Player& pA, Player& pB){
    pA.setChar('X');
    pB.setChar('O');
    while(!(this->checkWin())){
        if(!player){ // playerA's turn
            pA.play(*gameBoard);
            player = !player;
        }
        else{
            pB.play(*gameBoard);
            player = !player;
        }
    }
    
    if(gameWinner == 0){
        winnerName = pA.name();
    }
    else{
        winnerName = pB.name();
    }
    
}

bool TicTacToe::checkWin(){
    return checkRows() || checkCol() || checkMainDiag() || checkOtherDiag();
}

bool TicTacToe::checkTie(){
    if(!checkWin() && isFull()){
        return true;
    }
    return false;
}

bool TicTacToe::isFull(){
    uint n = gameBoard->size();
    for (uint i = 0; i < n; i++) {
        for (uint j = 0; j < n; i++) {
            if((*gameBoard)[{i,j}] == '.')
                return false;
        }
    }
    return true;
}

bool TicTacToe::checkRows(){
    int countCorrect;
    uint n = gameBoard->size();
    for (uint i = 0; i < n; i++) { // check for winning row
        countCorrect = 0;
        for (uint j = 0; j < n-1; j++) {
            if((*gameBoard)[{i,j}] != '.' && (*gameBoard)[{i,j}] == (*gameBoard)[{i,j+1}]){
                countCorrect++;
            }
        }
        if(countCorrect == n-1){
            if((*gameBoard)[{i,0}] == 'X'){
                gameWinner = 0;
            }
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkCol(){
    int countCorrect;
    uint n = gameBoard->size();
    
    for (uint j = 0; j < n; j++) { // check for winning colum
        countCorrect = 0;
        for (uint i = 0; i < n-1; i++) {
            if((*gameBoard)[{i,j}] != '.' && (*gameBoard)[{i,j}] == (*gameBoard)[{i+1,j}]){
                 countCorrect++;
            }
        }
        if(countCorrect == n-1){
            if((*gameBoard)[{0,j}] == 'X'){
                gameWinner = 0;
            }
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkMainDiag(){
    uint n = gameBoard->size();
    
    for (uint i = 0; i < n-1; i++) { // check for winning main diagonal
        if((*gameBoard)[{i,i}] == '.' || (*gameBoard)[{i,i}] != (*gameBoard)[{i+1,i+1}]){
                return false;
        }
    }
    
    if((*gameBoard)[{0,0}] == 'X'){
        gameWinner = 0;
    }
    
    return true;
}

bool TicTacToe::checkOtherDiag(){
    uint n = gameBoard->size();
    
    for (uint i = 0; i < n-1; i++) { // check for winning main diagonal
        if((*gameBoard)[{i,n-i-1}] == '.' || (*gameBoard)[{i,n-i-1}] != (*gameBoard)[{i+1,n-i-2}]){
                return false;
        }
    }
    
    if((*gameBoard)[{0,n-1}] == 'X'){
        gameWinner = 0;
    }
    
    return true;
}



Board TicTacToe::board() const{
    return *gameBoard;
}

Player& TicTacToe::winner() const{
    if(winnerName=="Champion"){
        Champion *temp = new Champion;
        return *temp;
    }
    if(winnerName=="XYPlayer"){
        XYPlayer *temp = new XYPlayer;
        return *temp;
    }
    if(winnerName=="YXPlayer"){
        YXPlayer *temp = new YXPlayer;
        return *temp;
    }
    if(winnerName=="IllegalPlayer"){
        IllegalPlayer *temp = new IllegalPlayer;
        return *temp;
    }
    if(winnerName=="ExceptionPlayer"){
        ExceptionPlayer *temp = new ExceptionPlayer;
        return *temp;
    }

}