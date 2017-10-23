

#ifndef Elf_hpp
#define Elf_hpp

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
#include "Constants.hpp"
#include "MainCharacter.hpp"
//per observer



class Elf : public MainCharacter{
public:
    
    Elf(int x, int y, int id, int life, int atk, std::string addr);
    
    ~Elf(){}
    
    void walk(int** walkMap, int index , int action);
    
};

#endif /* Elf_hpp */
