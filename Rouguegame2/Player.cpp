

#include <stdio.h>
#include "Player.h"


int Player::getPos(std::string p){
    if(p == "x"){
        return playersprite.getPosition().x;
    }
    else{
        return playersprite.getPosition().y;
    }
}
