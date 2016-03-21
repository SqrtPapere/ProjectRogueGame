//
//  Player.h
//  Rouguegame2
//
//  Created by Francesco Pegoraro on 20/03/16.
//  Copyright © 2016 Francesco Pegoraro. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <curses.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>



class Player
{
public:
    Player(std::string nome, int life, int atk){
        nome=n;
        this->atk=atk;
        this->life=life;
        source.x = 1;
        source.y = Down;
        updateFrame = false;
        frameCounter=0, switchFrame=100, frameSpeed = 800;
        
    }
    
    virtual void initP()=0;
    
    virtual void walk()=0;
    
    int getPos(std::string p);
    
    sf::Sprite getSprite(){
        return playersprite;
    }
 
protected:
    
    std::string n;
    std::string type;
    int life;
    int atk;
    
    enum Direction {Down, Left, Right, Up}; //downn=0,left=1, ecc..in ordine per righe della texture personaggio
    
    sf::Vector2i source;//indica source.x e source.y, y indichera lo start drawing nell immag
    bool updateFrame;
    float frameCounter, switchFrame, frameSpeed;
    sf::Clock clk;
    
    sf::Texture playerTexture;
    sf::Sprite playersprite;
    
};


#endif /* Player_h */
