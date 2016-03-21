
#include "BrickGround.hpp"
#include <stdio.h>



void BrickGround::initG(){
    if(!groundTexture.loadFromFile("grass1.png"))
        std::cout<<"grass not found"<<std::endl;
}
void BrickGround::loadG(){
    groundSprite.setTexture(groundTexture);
    groundSprite.setScale(1.5, 1.5); //scala del grass1
    
}