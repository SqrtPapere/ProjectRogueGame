

#ifndef Music_hpp
#define Music_hpp

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


class Music {
public:
    
    void playMusic(int m);
    
protected:
    
    sf::SoundBuffer soundtrack;
    sf::Sound sound;
    
};

#endif /* Music_hpp */
