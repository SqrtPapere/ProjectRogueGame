

#ifndef Elf_h
#define Elf_h

#include "Player.h"

class Elf : public Player{
public:
    
    Elf(std::string n = "NoName", int l = 0, int a = 0):Player(n,l,a){
        type = "Elf";
        initP();
    }
    
    void initP();
    
    void walk();
        
    
};
#endif /* Elf_h */
