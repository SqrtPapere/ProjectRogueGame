#ifndef Monster_hpp
#define Monster_hpp

#include <stdio.h>
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

#include "AbstractStrategy.hpp"
#include "TileMap.hpp"
#include "Character.hpp"
#include "Constants.hpp"


class Monster : public Character{
public:
    
    Monster(int x, int y, int id, int life, int atk, std::string addr);
    
    ~Monster(){}
    
    int getId(){
        return id;
    }
    
    void walk(int** walkMap, int index , int action);
    
    sf::Vector2i getPos(){
        return position;
    }
    
    sf::Sprite getSprite(){
        return playersprite;
    }
    
    std::string getType(){
        return type;
    }
    int getLife(){
        return life;
    }
    
    void reduceLife(int damage){
        life-=damage;
    }
    
    int getAttack(){
        return atk;
    }
    
    void SetTextureState();
    
    virtual void setHp(int hp){
        this->life = hp;
    }
    
    void SetStrategy(AbstractStrategy *abs){
        this->abs = abs;
    }
    
private:
    
    AbstractStrategy* abs;
    
};


#endif /* Monster_hpp */
