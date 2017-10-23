
#include "Map.hpp"


Map::Map(MainCharacter* p, int** mapCtor) {    //alla costruzione
    px = p;
    px->subscribe(this);
    lastJ=px->getPos().x;
    lastI=px->getPos().y;


    
    for(int i=0; i<dimMapx; i++){
        for(int j=0; j<dimMapy; j++){
            musicMap[i][j]=mapCtor[i][j];
        }
    }
}

Map::~Map(){
    px->unsubscribe(this);
}

void Map::update(){  //metodo update che non prende niente perchè pull ma chiama i get per sapere 
    currentI= px->getPos().x;
    currentJ= px->getPos().y;
    callMusic();
}


void Map::callMusic(){
    if(musicMap[currentI][currentJ] != musicMap[lastI][lastJ]){
        lastI=currentI;
        lastJ=currentJ;
        music.playMusic(musicMap[currentI][currentJ]);
    }
}

