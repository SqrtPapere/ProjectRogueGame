#ifndef Ground_h
#define Ground_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <curses.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <stdio.h>


class Ground {
    
public:
    
    Ground(std::string nome){
        this->nome=nome;
    }
    
    virtual void initG()=0;
    virtual void loadG()=0;
    
    sf::Sprite getGSprite(){
        return groundSprite;
    }


    
protected:
    
    sf::Texture groundTexture;
    sf::Sprite groundSprite;
    
    
    std::string type;
    
private:
    std::string nome;
   
    
};

#endif /* Ground_h */
