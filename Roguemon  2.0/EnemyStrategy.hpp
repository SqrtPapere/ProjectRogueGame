

#ifndef EnemyStrategy_hpp
#define EnemyStrategy_hpp

#include <stdio.h>
#include "AbstractStrategy.hpp"

class EnemyStrategy: public AbstractStrategy{
    
public:
    
    ~EnemyStrategy(){};
    
    void walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter);
    
private:
    
    int const static movsize = 12;
    int movements [movsize] = {3, 3, 3, 2, 2, 2, 4, 4, 4, 1, 1, 1};  //quadrato
    int i = 0;
    
};

#endif /* EnemyStrategy_hpp */
