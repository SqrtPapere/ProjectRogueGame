

#include "Music.h"


void Music::playMusic(){
    
    if(!soundtrack.loadFromFile("Music1.wav"))//carico soundtrack, **essendo lunga meglio fare Music1 e .ogg!!!
        std::cout<<"soundtrack not found"<<std::endl;
    
    sound.setBuffer(soundtrack);
    sound.play();
    sound.setVolume(20);
}
