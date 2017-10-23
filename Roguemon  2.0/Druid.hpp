

#ifndef Druid_hpp
#define Druid_hpp

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


class Druid : public MainCharacter{
public:
    
    Druid(int x, int y, int id, int life, int atk, std::string addr);
    
    ~Druid(){}
    

    
    
    void walk(int** walkMap, int index , int action);

    
protected:
   
    
};

#endif /* Druid_hpp */
