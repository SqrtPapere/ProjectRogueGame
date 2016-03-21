

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <curses.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>

#include "Elf.h"
#include "Music.h"
#include "GrassGround.h"


int main()
{
    
    sf::Vector2i screenDimensions(800, 600);
    //sf::Vector2i blockDimensions(10, 10);
    
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x,screenDimensions.y),"RogueGame");
    
    Music epicSong;
    epicSong.playMusic();
    
    Elf *p1 = new Elf("Gino",60, 70);
    
    GrassGround *gg = new GrassGround("terrain");
    gg->loadG();
    
    
    
    
        
    sf::View view;
    view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    view.setViewport(sf::FloatRect(0, 0 , 1, 1));
    
    sf::Vector2f position(0, 0);
    
    sf::Image icon;
    if (!icon.loadFromFile("iconB.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    
    //window.setKeyRepeatEnabled(false);

    
    while(window.isOpen()){
        window.clear();
        
        sf::Event Event;
        
        while(window.pollEvent(Event)){//loop degli eventi
            
            switch(Event.type){
                    
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        
        p1->walk();
        
        position.x=p1->getPos("x")+32 - (screenDimensions.x/2); //metto in position la posizione dell omino - mezzo display
        position.y=p1->getPos("y")+32 - (screenDimensions.y/2);
        if (position.x < 0)
            position.x=0;
        else if(position.x > 200)
                position.x=200;
        if (position.y < 0)
            position.y=0;
        else if(position.y > 150)
                position.y=150;
        view.reset(sf::FloatRect(position.x, position.y, screenDimensions.x, screenDimensions.y)); //cosicche se si passa il centro si muove la camera, e dopo un po si smette di muovere.
        
        
        window.setView(view);
        
        window.draw(gg->getGSprite());
        window.draw(p1->getSprite());
        window.display();
        window.clear();
        
    }//gameloop
}//main