
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "Monster.hpp"
#include "Elf.hpp"

Monster::Monster(int x, int y, int id, int life, int atk , std::string addr):Character(x, y, id, life, atk){
    if(!playerTexture.loadFromFile(addr))//carico l immag del persongg
        std::cout<<addr<<" not found"<<std::endl;
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(32*position.y,32*position.x);
    source.x = 1;
    source.y = Right;  //cambiare per posizione di partenza
    updateFrame = false;
    frameCounter=0, switchFrame=100, frameSpeed = 500;
  
    
    type="monster";
}

void Monster::SetTextureState(){
    if (updateFrame) {
        
        frameCounter = 0;
        source.x ++;//la camminata animata perchè scorre lungo la riga y
        
        if(source.x * 32 >= playerTexture.getSize().x)//e questo è per far ripartire la riga
            source.x=0;
    }
    
    playersprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
    
    updateFrame = false;
}


void Monster::walk(int** walkMap, int index , int action)
{
    abs->walkStrategy(walkMap, index, &position, &source, &updateFrame, &playersprite, &playerTexture, &frameCounter);
    
        
}

