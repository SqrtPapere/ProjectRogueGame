
#ifndef SandGround_h
#define SandGround_h


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



class SandGround : public Ground{
    
public:
    
    SandGround(std::string n):Ground(n){
        type="grass";
        initG();
    }
    
    void initG();
    void loadG();
    
};
#endif /* SandGround_h */