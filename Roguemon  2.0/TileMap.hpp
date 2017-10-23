

#ifndef TileMap_hpp
#define TileMap_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>




class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    
    bool load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    
private:
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif /* TileMap_hpp */
