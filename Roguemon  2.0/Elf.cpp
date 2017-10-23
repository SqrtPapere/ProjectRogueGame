#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "Elf.hpp"

Elf::Elf(int x, int y, int id, int life, int atk, std::string addr):MainCharacter(x, y, id, life, atk){
    if(!playerTexture.loadFromFile("Elf.png"))//carico l immag del persongg
        std::cout<<"Elf not found"<<std::endl;
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(32*position.y,32*position.x);
    source.x = 1;
    source.y = Right;  //cambiare per posizione di partenza
    updateFrame = false;
    frameCounter=0, switchFrame=200, frameSpeed = 500;
    
    type = "elf";
 
}


void Elf::walk(int** walkMap , int index , int action)
{
    if ( action == 1){ //indicheranno dove si muove il player nel display
        source.y = Down;//tutte scambiate per non cambiare la texture
        SetTextureState();
        if(walkMap[position.x-1][position.y] != 1){
            playersprite.setPosition((position.y)*32, (position.x)*32 - index);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.x--;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    else if(action == 2){
        source.y=Right;
        SetTextureState();
        if(walkMap[position.x+1][position.y] != 1){
            playersprite.setPosition((position.y)*32, (position.x)*32 + index);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.x++;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    else if(action == 3){
        source.y=Up;
        SetTextureState();
        if(walkMap[position.x][position.y+1] != 1){
            playersprite.setPosition((position.y)*32 +index, (position.x)*32);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.y++;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    else if(action == 4){
        source.y=Left;
        SetTextureState();
        if(walkMap[position.x][position.y-1] != 1){
            playersprite.setPosition((position.y)*32 -index, (position.x)*32);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.y--;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    notify();
}





