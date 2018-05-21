#include "Board.h"
#include <iostream>
using namespace std;


Board& Board::operator=(const char w){
    if(w == '.'|| w == 'O' || w == 'X'){
        for (int i = 0; i < bSize; i++) {
            for(int j = 0; j < bSize; j++){
                pBoard[i][j].data = w;
            }
        }
    }
    else{
        throw IllegalCharException(w);
    }
    return *this;
}

Board& Board::operator=(const Board& b){
    for (int i = 0; i < bSize; i++) {
        for(int j = 0; j < bSize; j++){
            pBoard[i][j].data=b.pBoard[i][j].data;
        }
    }
    return *this;
}

bool Board::operator == (Board const & r){
    if(bSize != r.size()) return false;
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if(pBoard[i][j] != r.pBoard[i][j]) return false;
        }
    }
    return true;
}


ostream& operator<<(ostream& os, Board const& b) {  
      for (int i = 0; i < b.size(); i++) {
        for(int j=0; j<b.size(); j++){
            os << b.pBoard[i][j].data;
        }
        os << endl;
      }
    return os;  
}

Coordinate& Board::operator[](Coordinate p){
    if(p.x < 0 || p.x >= bSize || p.y < 0 || p.y >= bSize){
        throw IllegalCoordinateException(p.x, p.y);
    }
    else{
        return pBoard[p.x][p.y];
    }

}

const Coordinate& Board::operator[](Coordinate p) const{
    if(p.x < 0 || p.x >= bSize || p.y < 0 || p.y >= bSize){
        throw IllegalCoordinateException(p.x, p.y);
    }
    else{
        return pBoard[p.x][p.y];
    }

}

int Board::size() const{
    return bSize;
}




