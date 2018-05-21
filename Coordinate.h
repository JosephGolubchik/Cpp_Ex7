#pragma once
#include <iostream>
#include "IllegalCharException.h"

using std::string;

class Coordinate{
    public:
    uint x;
    uint y;
    char data;
    
    Coordinate(){
        data = '.';
    }
    
    Coordinate(char c){
        this->data = c;
    }
    
    Coordinate(uint x,uint y){
        this->x = x;
        this->y = y;
        this->data = '.';
    }
    
    Coordinate(const Coordinate & p)
    {
        this->x = p.x;
        this->y = p.y;
        this->data = p.data;
    }
    
    Coordinate operator=(const char c);
    Coordinate& operator=(const Coordinate& p);
    
    friend std::ostream& operator<<(std::ostream& os, Coordinate& p) {  
        os << p.data;
        return os; 
    }
    operator char();
};

bool operator == (Coordinate const &, char const &);
bool operator != (Coordinate const &, char const &);
// char operator=(char c, Point& p);



    




