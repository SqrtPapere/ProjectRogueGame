//
//  MenuLoop.cpp
//  Roguemon  2.0
//
//  Created by Francesco Pegoraro on 30/06/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#include <stdio.h>
#include "MenuLoop.hpp"


int MenuLoop(){
    
    sf::RenderWindow window1(sf::VideoMode(32*16, 32*8), "Choose your Character");
    window1.setMouseCursorVisible(false);
    
    int k=1;  //a seconda dell'ultimo tasto premuto nel menu ritorna o 1 o 2 o 3
    
    
    //icon
    sf::Image icon;
    if (!icon.loadFromFile("icon.png")) {
        return EXIT_FAILURE;
    }
    window1.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
    sf::Text elfName, druidName, paladinName;
    elfName.setString("Legolas");
    druidName.setString("Radagast");
    paladinName.setString("Fra il giusto");
    
    //Font
    sf::Font font;
    if (!font.loadFromFile("Lobster_1.3.otf"))
    {
        std::cout<< "failed to open font"<<std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Menu");
    text.setCharacterSize(36); // in pixels, not points!
    text.setColor(sf::Color::Red);
    text.setPosition(32*7-24, 0);
    //Label Characters
    sf::Text Elflabel, Druidlabel, Paladinlabel;
    Elflabel.setFont(font);
    Druidlabel.setFont(font);
    Paladinlabel.setFont(font);
    Elflabel.setString("Elf");
    Druidlabel.setString("Druid");
    Paladinlabel.setString("Paladin");
    Elflabel.setCharacterSize(20); // in pixels, not points!
    Druidlabel.setCharacterSize(20); // in pixels, not points!
    Paladinlabel.setCharacterSize(20); // in pixels, not points!
    Elflabel.setColor(sf::Color::Blue);
    Druidlabel.setColor(sf::Color::Green);
    Paladinlabel.setColor(sf::Color::White);
    Elflabel.setPosition(34*3, 60);
    Druidlabel.setPosition(31*7-2, 60);
    Paladinlabel.setPosition(31*11-3, 60);
    //Character's stats
    sf::Text Elfstats;
    Elfstats.setFont(font);
    Elfstats.setString("attack: 50 \n life: 80");
    Elfstats.setCharacterSize(15); // in pixels, not points!
    Elfstats.setColor(sf::Color::White);
    Elfstats.setPosition(30*3, 145);
    sf::Text Druidstats;
    Druidstats.setFont(font);
    Druidstats.setString("attack: 60 \n life: 70");
    Druidstats.setCharacterSize(15); // in pixels, not points!
    Druidstats.setColor(sf::Color::White);
    Druidstats.setPosition(31*7-5, 145);
    sf::Text Paladinstats;
    Paladinstats.setFont(font);
    Paladinstats.setString("attack: 70 \n life: 60");
    Paladinstats.setCharacterSize(15); // in pixels, not points!
    Paladinstats.setColor(sf::Color::White);
    Paladinstats.setPosition(32*11-10, 145);
    
    
    //Character frontal sprites
    sf::Texture elfTexture, druidTexture, paladinTexture;
    sf::Sprite elfSprite, druidSprite, paladinSprite;
    
    if(!elfTexture.loadFromFile("Elf.png"))
        std::cout<<"Error, could not load elf texture"<<std::endl;
    elfSprite.setTexture(elfTexture);
    elfSprite.setTextureRect(sf::IntRect(0,64,32,32));
    elfSprite.setPosition(32*3,100);
    
    if(!druidTexture.loadFromFile("Druid.png"))
        std::cout<<"Error, could not load druid texture"<<std::endl;
    druidSprite.setTexture(druidTexture);
    druidSprite.setTextureRect(sf::IntRect(0,32,32,32));
    druidSprite.setPosition(32*7,100);
    
    if(!paladinTexture.loadFromFile("Paladin.png"))
        std::cout<<"Error, could not load paladin texture"<<std::endl;
    paladinSprite.setTexture(paladinTexture);
    paladinSprite.setTextureRect(sf::IntRect(0,32,32,32));
    paladinSprite.setPosition(32*11,100);
    
    //animazione quadrato di selezione
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(40, 40));
    rectangle.setOutlineColor(sf::Color::Yellow);
    rectangle.setOutlineThickness(5);
    rectangle.setFillColor(sf::Color::Color(0,0,0,0));
    rectangle.setPosition(32*3-4, 100);
    sf::Event eevv;
    
    while (window1.isOpen()){
        while (window1.pollEvent(eevv)){
            if(eevv.type == sf::Event::Closed){
                window1.close();
                k=-1;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window1.close();
            }
            else if (eevv.key.code==sf::Keyboard::Left){
                rectangle.setPosition((32*3)-4,100);
                k=1;
            }
            else if(eevv.key.code==sf::Keyboard::Up){
                rectangle.setPosition((32*7)-4,100);
                k=2;
            }
            else if(eevv.key.code==sf::Keyboard::Right){
                rectangle.setPosition((32*11)-4,100);
                k=3;
            }
            else if(eevv.key.code==sf::Keyboard::Return){
                window1.close();
            }
            
            window1.clear();
            window1.draw(text);
            window1.draw(elfSprite);
            window1.draw(druidSprite);
            window1.draw(paladinSprite);
            window1.draw(Elflabel);
            window1.draw(Druidlabel);
            window1.draw(Paladinlabel);
            window1.draw(Elfstats);
            window1.draw(Druidstats);
            window1.draw(Paladinstats);
            window1.draw(rectangle);
            window1.display();
        }
        
    }
    return k;
}

int getPressedKey(){
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        return 1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        return 2;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        return 3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        return 4;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        return 5;
    }
    else return -1;
}
