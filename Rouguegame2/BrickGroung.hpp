
#ifndef BrickGround_h
#define BrickGround_h


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



class BrickGround : public Ground{
    
public:
    
    BrickGround(std::string n):Ground(n){
        type="brick";
        initG();
    }
    
    void initG();
    void loadG();
    
};
#endif /* BrickGround_h */