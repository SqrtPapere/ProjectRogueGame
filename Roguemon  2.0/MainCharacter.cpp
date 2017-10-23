
#include "MainCharacter.hpp"



//per observer
void MainCharacter::subscribe(Observer* o){
    observers.push_back(o);
}

void MainCharacter::unsubscribe(Observer* o){
    observers.remove(o);
}

void MainCharacter::notify(){
    std::list <Observer *>::iterator itr;
    for (itr = observers.begin(); itr != observers.end(); itr++){
        (*itr) -> update();
    }
    
}

void MainCharacter::SetTextureState(){
    if (updateFrame) {
        
        frameCounter = 0;
        source.x ++;//la camminata animata perche scorre lungo la riga y
        
        if(source.x * 32 >= playerTexture.getSize().x)//e questo è per far ripartire la riga
            source.x=0;
    }
    
    playersprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
    updateFrame = false;
}