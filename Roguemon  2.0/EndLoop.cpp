

#include "EndLoop.hpp"



void EndLoop(std::vector<Character*> chrt){
    sf::RenderWindow window3(sf::VideoMode(32*16, 32*8), "This is the End");
    
    window3.setMouseCursorVisible(false);
    
    
    
    //Font
    sf::Font font;
    if (!font.loadFromFile("Lobster_1.3.otf"))
    {
        std::cout<< "failed to open font"<<std::endl;
    }
    
    sf::Text end, info;
    end.setFont(font);
    info.setFont(font);
    info.setColor(sf::Color::White);
    
    if (chrt.at(0)->getType()=="monster") {
        end.setString("You Lose");
        end.setColor(sf::Color::Cyan);
        
    }
    else{
        end.setString("You Win");
        end.setColor(sf::Color::Magenta);
        
        
    }
    
    end.setCharacterSize(36); // in pixels, not points!
    end.setPosition(2*95, 80);
    info.setCharacterSize(20);
    info.setPosition(3*67, 4*57);
    info.setString("Press [esc] to leave");
    
    sf::Event eevv;
    
    while (window3.isOpen()){
        window3.clear();
        window3.draw(end);
        window3.draw(info);
        window3.display();
        while (window3.pollEvent(eevv)){
            
            if(eevv.key.code==sf::Keyboard::Escape){
                window3.close();
            }
            
            window3.clear();
            window3.draw(end);
            window3.draw(info);
            window3.display();
        }
        
    }
}
