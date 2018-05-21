#include "Player.h"

const string Player::name() const{
    return sName;
}

char Player::getChar(){
    return myChar;
}

void Player::setChar(char myChar){
    this->myChar = myChar;
}
