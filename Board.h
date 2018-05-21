#pragma once
#include <iostream>

#include "Coordinate.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

class Board {
    public:
    int bSize;
    Coordinate **pBoard;

    Board(int size){
        bSize = size;
        pBoard = new Coordinate*[size];
        for(int i = 0; i < size; i++){
            pBoard[i] = new Coordinate[size];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++){
            pBoard[i][j].x = i;
            pBoard[i][j].y = j;
            }
        }
    };
    
            

    Board(const Board& b){
        bSize = b.size();
        pBoard = new Coordinate*[bSize];
        for(int i = 0; i < bSize; i++){
            pBoard[i] = new Coordinate[bSize];
        }
        for (int i = 0; i < bSize; i++) {
            for (int j = 0; j < bSize; j++){
                pBoard[i][j].x = i;
                pBoard[i][j].y = j;
            }
        }
        *this = b;
    }
    
    ~Board(){
        delete &bSize;
	    for (int i = 0; i < bSize; i++) {
            delete[] pBoard[i];
        }   
        delete[] pBoard;
    }
    
    
    
    Board& operator=(const char w);
    Board& operator=(const Board& b);
    friend std::ostream& operator<<(std::ostream& os, Board const& b);
    // int getIndex(int x,int y);
    int size() const;
    Coordinate& operator[](Coordinate p);
    const Coordinate& operator[](Coordinate p) const;
    bool operator == (Board const & r);
};
