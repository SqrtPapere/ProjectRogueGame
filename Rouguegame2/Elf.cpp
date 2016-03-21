

#include <stdio.h>
#include "Elf.h"


void Elf::initP()
{
    if(!playerTexture.loadFromFile("image1.png"))//carico l immag del persongg
        std::cout<<"image1 not found"<<std::endl;
    
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(100, 100);
}


void Elf::walk()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //indicheranno dove si muove il player nel display
        source.y=Up;
        playersprite.move(0, -1); //spostamento sul display
        updateFrame = true;
    }   
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        source.y=Down;
        playersprite.move(0, 1);
        updateFrame = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        source.y=Right;
        playersprite.move(1, 0);
        updateFrame = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        source.y=Left;
        playersprite.move(-1, 0);
        updateFrame=true;
    }
    
    if (updateFrame) {
        frameCounter+=frameSpeed * clk.restart().asSeconds();
    }
    else {
        frameCounter = 0;
        source.x=1;
    } //se non premo le frecce, mi rimane in piedi rettilineo
    
    if (frameCounter >= switchFrame){
        
        frameCounter=0;
        source.x++;//la camminata animata perche scorre lungo la riga y
        
        if(source.x*32 >= playerTexture.getSize().x)//e questo è per far ripartire la riga
            source.x=0;
            }
    
    playersprite.setTextureRect(sf::IntRect(source.x*32,source.y*32,32,32));
    //grass1Sprite.setTextureRect(sf::IntRect(0, screenDimensions.y, screenDimensions.x, screenDimensions.y));
    
    updateFrame = false;
    
    
}
