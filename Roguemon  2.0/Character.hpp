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

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Subject.hpp"

#include "AbstractStrategy.hpp"

class Character{
    
public:
    
    Character(int x, int y, int id, int life, int atk);
    
    virtual ~Character() = 0;
    
    virtual int getId() = 0;
    
    virtual void walk(int** walkMap, int index , int action) = 0;
    
    virtual sf::Vector2i getPos() = 0;
    
    virtual sf::Sprite getSprite() = 0;
    
    virtual std::string getType() = 0;
    
    virtual int getLife() = 0;
    
    virtual int getAttack() = 0;
    
    virtual void reduceLife(int damage) = 0;
    
    virtual void setHp(int hp) = 0;

    virtual void SetTextureState() = 0;
        
protected:
    
    int id;
    int atk;
    int life;
    
    sf::Vector2i position;
    enum Direction {Down, Left, Right, Up};
    sf::Vector2i source;
    
    bool updateFrame;
    float frameCounter, switchFrame, frameSpeed;
    sf::Clock clk;
    
    sf::Texture playerTexture;
    sf::Sprite playersprite;
    std::string type;

    
};


#endif /* Character_hpp */
