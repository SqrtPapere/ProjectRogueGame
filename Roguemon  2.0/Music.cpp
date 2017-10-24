
#include "Music.hpp"
#include <iostream>
#include "ResourcePath.hpp"


void Music::playMusic(int m){
    std::string file = std::to_string(m) + ".ogg";
    if(!soundtrack.loadFromFile(resourcePath() + file))//carico soundtrack
        std::cout<<m<<" not found"<<std::endl;
    sound.setBuffer(soundtrack);
    sound.play();
    sound.setVolume(30);
}
