
#ifndef GrassGround_h
#define GrassGround_h


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
#include "Ground.h"



class GrassGround : public Ground{
    
public:
    
    GrassGround(std::string n):Ground(n){
        type="grass";
        initG();
    }
    
    void initG();
    void loadG();
           
};
#endif /* GrassGround_h */