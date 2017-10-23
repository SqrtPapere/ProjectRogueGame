//
//  EnemyStrategy4.hpp
//  Roguemon  2.0
//
//  Created by Francesco Pegoraro on 25/06/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#ifndef EnemyStrategy4_hpp
#define EnemyStrategy4_hpp

#include <stdio.h>
#include "AbstractStrategy.hpp"



class EnemyStrategy4: public AbstractStrategy{
    
public:
    
    ~EnemyStrategy4(){};
    
    void walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter);
    
private:
    
    int const static movsize = 14;
    int movements [movsize] = {2, 2, 2, 2, 2, 2, 4, 1, 1, 1, 1, 1, 1, 3};  //rect verticale
    int i = 0;
    
};

#endif /* EnemyStrategy4_hpp */
