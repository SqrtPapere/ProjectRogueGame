
#include "EnemyStrategy2.hpp"

void EnemyStrategy2::walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter){
    
    int action = movements[i];
    
    //iterator = (iterator + buffer_size - 1) % buffer_size
    
    if ( action == 1){ //indicheranno dove si muove il player nel display
        source->y = Down;
        if (updateframe) {
            
            frameCounter = 0;
            source->x ++;//la camminata animata perchè scorre lungo la riga y
            
            if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                source->x=0;
        }
        
        playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
        
        *updateframe = false;
        if(walkMap[position->x-1][position->y] != 1){
            playersprite->setPosition((position->y)*32, (position->x)*32 - index);
            if(index % 8 == 0){
                
                *updateframe = true;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
            if(index == 32){
                i=(i+1)%movsize;
                position->x--;
                *updateframe = true;
                source->x = 0;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
        }
        else i=(i+1)%movsize;
        
    }
    else if(action == 2){
        source->y=Right;
        if (updateframe) {
            
            frameCounter = 0;
            source->x ++;//la camminata animata perchè scorre lungo la riga y
            
            if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                source->x=0;
        }
        
        playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
        
        *updateframe = false;
        if(walkMap[position->x+1][position->y] != 1){
            playersprite->setPosition((position->y)*32, (position->x)*32 + index);
            if(index % 8 == 0){
                *updateframe = true;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
            if(index == 32){
                i=(i+1)%movsize;
                position->x++;
                *updateframe = true;
                source->x = 0;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
        }
        else i=(i+1)%movsize;
    }
    else if(action == 3){
        source->y=Up;
        if (updateframe) {
            
            frameCounter = 0;
            source->x ++;//la camminata animata perchè scorre lungo la riga y
            
            if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                source->x=0;
        }
        
        playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
        
        *updateframe = false;
        if(walkMap[position->x][position->y+1] != 1){
            playersprite->setPosition((position->y)*32 + index, (position->x)*32);
            if(index % 8 == 0){
                
                *updateframe = true;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
            if(index == 32){
                i=(i+1)%movsize;
                position->y++;
                *updateframe = true;
                source->x = 0;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
        }
        else i=(i+1)%movsize;
    }
    else if(action == 4){
        source->y=Left;
        if (updateframe) {
            
            frameCounter = 0;
            source->x ++;//la camminata animata perchè scorre lungo la riga y
            
            if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                source->x=0;
        }
        
        playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
        
        *updateframe = false;
        if(walkMap[position->x][position->y-1] != 1){
            playersprite->setPosition((position->y)*32 -index, (position->x)*32);
            if(index % 8 == 0){
                
                *updateframe = true;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
            if(index == 32){
                i=(i+1)%movsize;
                position->y--;
                *updateframe = true;
                source->x = 0;
                if (updateframe) {
                    
                    frameCounter = 0;
                    source->x ++;//la camminata animata perchè scorre lungo la riga y
                    
                    if(source->x * 32 >= playerTexture->getSize().x)//e questo è per far ripartire la riga
                        source->x=0;
                }
                
                playersprite->setTextureRect(sf::IntRect(source->x * 32, source->y * 32, 32, 32));
                
                *updateframe = false;
            }
        }
        else i=(i+1)%movsize;
    }
}
