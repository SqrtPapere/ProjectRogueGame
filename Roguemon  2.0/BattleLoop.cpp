/*Copyright {2015} {Francesco Pegoraro}

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   */

#include "BattleLoop.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdexcept>



void BattleLoop(std::vector<Character*> *chrt, int ID){
    
    Character *player = chrt->at(0);
    Character *enemy =  chrt->at(ID);
    
    //grafica battle
    //sf::Texture playerTexture, enemyTexture, battleTexture;
    sf::Sprite playerSprite;
    sf::Sprite enemySprite;
    sf::Sprite battleSprite;
    
    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Texture battleTexture;
    
    sf::RectangleShape rectp;
    sf::RectangleShape recte;
    
    rectp.setSize(sf::Vector2f(100, 50));
    recte.setSize(sf::Vector2f(100, 50));
    
    rectp.setOutlineColor(sf::Color::Red);
    recte.setOutlineColor(sf::Color::Red);
    
    rectp.setOutlineThickness(5);
    recte.setOutlineThickness(5);
    
    rectp.setPosition(400, 200);
    recte.setPosition(20, 10);
    
    sf::Font font;
    if (!font.loadFromFile("LeagueGothic.otf"))
    {
        std::cout<< "failed to open font"<<std::endl;
    }
    
    sf::Text playerlife;
    sf::Text enemylife;
    
    playerlife.setColor(sf::Color::Black);
    enemylife.setColor(sf::Color::Black);
    
    playerlife.setFont(font);
    enemylife.setFont(font);
    
    playerlife.setCharacterSize(30);
    enemylife.setCharacterSize(30);
    
    playerlife.setPosition(402, 200);
    enemylife.setPosition(22, 10);
    
    playerlife.setString("hp: " + std::to_string(player->getLife()));
    enemylife.setString("hp: " + std::to_string(enemy->getLife()));
    
    std::string playerpng = player->getType() + "battle.png";
    if(!playerTexture.loadFromFile(playerpng))
        std::cout<<"Error, could not load "<<playerpng<<std::endl;
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0,0,110,128));
    playerSprite.setPosition(32,128);
    
    std::string enemypng = std::to_string(enemy->getId()) + ".png";//prendo l'id del mostro perchè la frontalsprite del mostro si chiama ID.png
    if(!enemyTexture.loadFromFile(enemypng))
        std::cout<<"Error, could not load  "<<enemypng<<std::endl;
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(32*10,50);
    
    if(!battleTexture.loadFromFile("battlebackground.png"))
        std::cout<<"Error, could not load battlebackground texture"<<std::endl;
    battleSprite.setTexture(battleTexture);
    battleSprite.setScale(2.2, 2.4);
    
    bool enemyatk = false;
    
    sf::RenderWindow window2(sf::VideoMode(32*16, 32*8), "Battle!!");
     window2.setKeyRepeatEnabled(false);
    //window2.setMouseCursorVisible(false);
    
    sf::Event events;
    
    std::cerr<<"Rendering event loop: start"<<std::endl;
    window2.clear();
    window2.draw(battleSprite);
    window2.draw(playerSprite);
    window2.draw(rectp);
    window2.draw(recte);
    window2.draw(enemySprite);
    window2.draw(playerlife);
    window2.draw(enemylife);
    window2.display();
    std::cerr<<"Rendering event loop: end"<<std::endl;
    
    while (window2.isOpen()){
        
        window2.clear();
        
        window2.draw(battleSprite);
        window2.draw(playerSprite);
        window2.draw(rectp);
        window2.draw(recte);
        window2.draw(enemySprite);
        window2.draw(playerlife);
        window2.draw(enemylife);
        window2.display();
        
        while (window2.pollEvent(events)){
            
            
            if(events.type == sf::Event::Closed){
                window2.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window2.close();
            }
            if (events.type == sf::Event::KeyPressed) {
                
                
                if (events.key.code==sf::Keyboard::Space) {
                    
                    //std::cout << "0 - windowcode: " << window2 << std::endl;
                    
                    playerlife.setString("hp: " + std::to_string(player->getLife()));
                    enemylife.setString("hp: " + std::to_string(enemy->getLife()));
                    
                    int succesnem = 50;//rand()%100;
                    int succesplay = 50; //rand()%100;
                    
                    std::cout<<succesnem<<"-----"<<succesplay<<std::endl;
                    
                    if (succesplay<60) {
                        enemy->setHp(enemy->getLife()-player->getAttack());
                    }
                    
                    enemyatk=true;
                    
                    if (enemy->getLife()<=0) {
                        
                        chrt->erase(chrt->begin()+ID);
                        enemyatk=false;
                        window2.close();
                    }
                    
                    if (enemyatk) {
                        if (succesnem<60) {
                            player->setHp(player->getLife()-enemy->getAttack());
                                                    }
                        enemyatk = false;
                    }

                    
                    playerlife.setString("hp: " + std::to_string(player->getLife()));
                    enemylife.setString("hp: " + std::to_string(enemy->getLife()));
                    
                    if (player->getLife()<=0) {
                        chrt->erase(chrt->begin());
                        window2.close();
                    }
                    
                    
                    window2.clear();
                    
                    window2.draw(battleSprite);
                    window2.draw(playerSprite);
                    window2.draw(rectp);
                    window2.draw(recte);
                    window2.draw(enemySprite);
                    window2.draw(playerlife);
                    window2.draw(enemylife);
                    window2.display();
                    
                }
                
                
            }
            
            /*std::cerr<<"Rendering event loop: start"<<std::endl;
            window2->clear();
            window2->draw(*battleSprite);
            window2->draw(*playerSprite);
            window2->draw(*rectp);
            window2->draw(*recte);
            window2->draw(*enemySprite);
            window2->draw(*playerlife);
            window2->draw(*enemylife);
            window2->display();
             */
        
            
        }//eventloop
     
    }//gameloop

}

bool collision (sf::Vector2f vp1, sf::Vector2f vp2){  //metodo per collisioni con nemici, se ci troviamo in un raggio di 4px
    float a=fabs(vp1.x-vp2.x);  //fabs fa il valore assoluto
    float b=fabs(vp1.y-vp2.y);
    if (a<4 && b<4) {
        return true;
    }
    return false;
}
