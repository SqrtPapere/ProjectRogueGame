
#ifndef MainCharacter_hpp
#define MainCharacter_hpp

#include <stdio.h>
#include "Character.hpp"
#include "Subject.hpp"
#include "Music.hpp"

#include <list>
#include <vector>



class MainCharacter :public Character, public Subject{
    
public:
    
    MainCharacter(int x, int y, int id, int life, int atk):Character(x, y, id, life, atk){}

    
    void walk(int** walkMap, int index , int action){
    }
    
    int getId(){
        return id;
    }
    
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
    
    int getAttack(){
        return atk;
    }

    void reduceLife(int damage){
        life-=damage;
    }
    
    virtual void setHp(int hp){
        this->life = hp;
    }
    
    void SetTextureState();
    
    std::list <Observer*> observers;
    
    void subscribe(Observer* o);
    
    void unsubscribe(Observer* o);
    
    void notify();
   
protected:
    
};


#endif /* MainCharacter_hpp */
