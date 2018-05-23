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
                    throw string("Illegal Player");
                }
                else{
                    (*gameBoard)[chosenSpot] = 'X';
                    player = !player;
                    (*finalBoard) = (*gameBoard);
                    if(checkTie()){
                        winner = 1;
                        finished = true;
                    }
                    if(checkWin()) finished = true;
                    cout << this->board() << endl;
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
                    throw string("Illegal Player");
                }
                else{
                    (*gameBoard)[chosenSpot] = 'O';
                    player = !player;
                    (*finalBoard) = (*gameBoard);
                    if(checkWin()) finished = true;
                    cout << this->board() << endl;
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
        for (uint j = 0; j < n; i++) {
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
            else{
                gameWinner = 1;
            }
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkCol(){
    uint countCorrect;
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
            else{
                gameWinner = 1;
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
    else{
        gameWinner = 1;
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
    else{
        gameWinner = 1;
    }
    
    return true;
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
    

}
