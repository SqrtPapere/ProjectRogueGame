
#include "SandGround.hpp"
#include <stdio.h>



void SandGround::initG(){
    if(!groundTexture.loadFromFile("grass1.png"))
        std::cout<<"grass not found"<<std::endl;
}
void SandGround::loadG(){
    groundSprite.setTexture(groundTexture);
    groundSprite.setScale(1.5, 1.5); //scala del grass1
    
}