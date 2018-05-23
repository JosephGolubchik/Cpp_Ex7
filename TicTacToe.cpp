#include "TicTacToe.h"

void TicTacToe::play(Player& pA, Player& pB){
    pA.setChar('X');
    pB.setChar('O');
    
    (*finalBoard) = '.';
    
    int i = 0;
    while(!finished){
        if(!player){ // playerA's turn
            try{
                Coordinate chosenSpot = pA.play(*gameBoard);
                if ((*gameBoard)[chosenSpot] != '.'){
                    // cout << "illegal move at " << chosenSpot.x << "," << chosenSpot.y << endl;
                    throw string("Illegal Player");
                }
                else{
                    (*gameBoard)[chosenSpot] = 'X';
                    player = !player;
                    (*finalBoard) = (*gameBoard);
                    if(checkWin()){
                        gameWinner = 0;
                        finished = true;
                    }
                    else if(isFull()){
                        gameWinner = 1;
                        finished = true;
                    }
                    // cout << this->board() << endl;
                }
            }
            catch(...){
                gameWinner = 1;
                winnerName = pB.name();
                initBoard();
                return;
            }
        }
        else{
            try{
                Coordinate chosenSpot = pB.play(*gameBoard);
                if ((*gameBoard)[chosenSpot] != '.'){
                    // cout << "illegal move at " << chosenSpot.x << "," << chosenSpot.y << endl;
                    throw string("Illegal Player");
                }
                else{
                    (*gameBoard)[chosenSpot] = 'O';
                    player = !player;
                    (*finalBoard) = (*gameBoard);
                    if(checkWin()){
                        gameWinner = 1;
                        finished = true;
                    }
                    else if(isFull()){
                        gameWinner = 1;
                        finished = true;
                    }
                    // cout << this->board() << endl;
                }
            }
            catch(...){
                gameWinner = 0;
                winnerName = pA.name();
                initBoard();
                return;
            }
        }
        
    }
    
    if(pA.name() == "Champion") pA.firstMove = 0;
    if(pB.name() == "Champion") pB.firstMove = 0;
    
    if(gameWinner == 0){
        winnerName = pA.name();
    }
    else{
        winnerName = pB.name();
    }
    initBoard();
    
}

void TicTacToe::initBoard(){
    (*gameBoard) = '.';
    player = 0;
    finished = 0;
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
        for (uint j = 0; j < n; j++) {
            if((*gameBoard)[{i,j}] == '.')
                return false;
        }
    }
    return true;
}

bool TicTacToe::checkRows(){
    uint countCorrect;
    uint n = gameBoard->size();
    for (uint i = 0; i < n; i++) { // check for winning row
    
        int countX = 0;
        int countO = 0;
        
        for (int j = 0; j < n; j++) {
            if((*gameBoard)[{i,j}] == 'X') countX++;
            if((*gameBoard)[{i,j}] == 'O') countO++;
        }
        
        if (countX == n){
            gameWinner = 0;
            return true;
        }
        
        if (countO == n){
            gameWinner = 1;
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkCol(){
    uint countCorrect;
    uint n = gameBoard->size();
    
    for (uint j = 0; j < n; j++) { // check for winning colum
        
        int countX = 0;
        int countO = 0;
        
        for (int i = 0; i < n; i++) {
            if((*gameBoard)[{i,j}] == 'X') countX++;
            if((*gameBoard)[{i,j}] == 'O') countO++;
        }
        
        if (countX == n){
            gameWinner = 0;
            return true;
        }
        
        if (countO == n){
            gameWinner = 1;
            return true;
        }
        
    }
    return false;
}

bool TicTacToe::checkMainDiag(){
    uint n = gameBoard->size();
    
    int countX = 0;
    int countO = 0;
    
    for (int i = 0; i < n; i++) {
        if((*gameBoard)[{i,i}] == 'X') countX++;
        if((*gameBoard)[{i,i}] == 'O') countO++;
    }
    
    if (countX == n){
        gameWinner = 0;
        return true;
    }
        
    if (countO == n){
        gameWinner = 1;
        return true;
    }
    
    return false;
}

bool TicTacToe::checkOtherDiag(){
    
    uint n = gameBoard->size();
    
    int countX = 0;
    int countO = 0;
    
    for (int i = 0; i < n; i++) {
        if((*gameBoard)[{i,n-i-1}] == 'X') countX++;
        if((*gameBoard)[{i,n-i-1}] == 'O') countO++;
    }
    
    
    if (countX == n){
        gameWinner = 0;
        return true;
    }
        
    if (countO == n){
        gameWinner = 1;
        return true;
    }
    
    return false;
}



Board TicTacToe::board() const{
    return (*finalBoard);
}

Player& TicTacToe::winner() const{
    if(gameWinner == 0){
        if(winnerName=="Champion"){
            Champion *temp = new Champion;
            temp->setChar('X');
            return *temp;
        }
        if(winnerName=="XYPlayer"){
            XYPlayer *temp = new XYPlayer;
            temp->setChar('X');
            return *temp;
        }
        if(winnerName=="YXPlayer"){
            YXPlayer *temp = new YXPlayer;
            temp->setChar('X');
            return *temp;
        }
        if(winnerName=="IllegalPlayer"){
            IllegalPlayer *temp = new IllegalPlayer;
            temp->setChar('X');
            return *temp;
        }
        if(winnerName=="ExceptionPlayer"){
            ExceptionPlayer *temp = new ExceptionPlayer;
            temp->setChar('X');
            return *temp;
        }
    }
    else{
        if(winnerName=="Champion"){
            Champion *temp = new Champion;
            temp->setChar('O');
            return *temp;
        }
        if(winnerName=="XYPlayer"){
            XYPlayer *temp = new XYPlayer;
            temp->setChar('O');
            return *temp;
        }
        if(winnerName=="YXPlayer"){
            YXPlayer *temp = new YXPlayer;
            temp->setChar('O');
            return *temp;
        }
        if(winnerName=="IllegalPlayer"){
            IllegalPlayer *temp = new IllegalPlayer;
            temp->setChar('O');
            return *temp;
        }
        if(winnerName=="ExceptionPlayer"){
            ExceptionPlayer *temp = new ExceptionPlayer;
            temp->setChar('O');
            return *temp;
        }
    }
    
    ExceptionPlayer *temp = new ExceptionPlayer;
    temp->setChar('X');
    return *temp;
}
