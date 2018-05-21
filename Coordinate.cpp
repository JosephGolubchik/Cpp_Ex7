#include "Board.h"
#include "Coordinate.h"
#include <iostream>
using namespace std;

Coordinate Coordinate::operator=(const char c){
    
    if (c == '.' || c == 'X' || c == 'O')
        data = c;
    else {
        IllegalCharException ex {c};
        throw ex;
    }
    return *this;
}

Coordinate& Coordinate::operator=(const Coordinate& p){
    data = p.data;
    return *this;
}

Coordinate::operator char(){
    return data;
}

// bool Point::operator==(const char c){
//     if(data == c){
//         return data == c;
//     }
//     else{
//         throw 0;
//     }
// }
// Point::~Point(){}

bool operator == (Coordinate const & l, char const & r){
    return l.data == r;
}

bool operator != (Coordinate const & l, char const & r){
    return l.data != r;
}

// char operator= (char c, Point& p){ 
//     return p.data;
// }