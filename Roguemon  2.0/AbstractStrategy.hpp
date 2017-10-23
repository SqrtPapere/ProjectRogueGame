
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
#ifndef AbstractStrategy_hpp
#define AbstractStrategy_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class AbstractStrategy{
    
public:
    
    AbstractStrategy(){
    }
    
    virtual ~AbstractStrategy() = 0;
    
    
    virtual void walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter) = 0;
    
protected:
    
    enum Direction {Down, Left, Right, Up};
    
};


#endif /* AbstractStrategy_hpp */
