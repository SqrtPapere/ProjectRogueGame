
#include "GrassGround.h"
#include <stdio.h>



void GrassGround::initG(){
    if(!groundTexture.loadFromFile("grass1.png"))
        std::cout<<"grass not found"<<std::endl;
}
void GrassGround::loadG(){
    groundSprite.setTexture(groundTexture);
    groundSprite.setScale(1.5, 1.5); //scala del grass1
    
}