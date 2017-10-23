#ifndef EnemyStrategy2_hpp
#define EnemyStrategy2_hpp


#include <stdio.h>
#include "AbstractStrategy.hpp"

class EnemyStrategy2: public AbstractStrategy{
    
public:
    
    ~EnemyStrategy2(){};
    
    void walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter);
    
private:
    
    int const static movsize = 14;
    int movements [movsize] = {3, 3, 3, 3, 3, 3, 2, 4, 4, 4, 4, 4, 4, 1 }; //rect orizzontale
    int i = 0;
    
};



#endif /* EnemyStrategy2_hpp */
