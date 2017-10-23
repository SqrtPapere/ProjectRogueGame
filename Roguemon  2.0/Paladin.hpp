

#ifndef Paladin_hpp
#define Paladin_hpp


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

#include "TileMap.hpp"
#include "MainCharacter.hpp"
#include "Constants.hpp"


class Paladin : public MainCharacter{
public:
    
    Paladin(int x, int y, int id, int life, int atk, std::string addr);
        
    ~Paladin(){
        
    }

    void walk(int** walkMap, int index , int action);
    
};


#endif /* Paladin_hpp */
