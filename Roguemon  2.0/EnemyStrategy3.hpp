

#ifndef EnemyStrategy3_hpp
#define EnemyStrategy3_hpp

#include "AbstractStrategy.hpp"
#include <stdio.h>



class EnemyStrategy3: public AbstractStrategy{
    
public:
    
    ~EnemyStrategy3(){};
    
    void walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter);
    
private:
    
    int const static movsize = 16;
    int movements [movsize] = {1, 3, 1, 3, 1, 3, 2, 3, 2, 3, 2, 4, 4, 4, 4, 4}; //triangolo
    int i = 0;
    
};


#endif /* EnemyStrategy3_hpp */
