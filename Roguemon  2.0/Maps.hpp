

#ifndef Maps_hpp
#define Maps_hpp

#include <stdio.h>
#include "Constants.hpp"

int** baseMap;

int** walkMap;

int* level;

int** createBaseMap(unsigned height, unsigned width)
{
    int** array2D = 0;
    array2D = new int*[height];
    
    for (int h = 0; h < height; h++)
    {
        array2D[h] = new int[width];
        
        for (int w = 0; w < width; w++)
        {
            if (h==0 || w==0 || h==(width-1) || w==(height-1))
                array2D[h][w]=0;
            else array2D[h][w]=1;

        }
    }
    
    return array2D;
}

int** createWalkable(unsigned height, unsigned width){
    int** array2D=0;
    array2D=new int*[height];
    for(int h=0; h<height; h++){
        array2D[h]=new int[width];
        for(int w=0; w<width; w++){
            if(baseMap[h][w]==0 || baseMap[h][w]==4 || baseMap[h][w]==5)
                array2D[h][w]=1;
            else array2D[h][w]=0;
        }
    }
    return array2D;
}
int* createLevel(unsigned height, unsigned width){
    int* array=0;
    unsigned count=0;
    array=new int[height*width];
    for(int h=0; h<height; h++){
        for(int w=0; w<width; w++){
            array[count]=baseMap[h][w];
            count++;
        }
    }
    return array;
}



void generateTrees(unsigned height, unsigned width, int** mappaBase){
    for(int h=0; h<height; h++){
        for(int w=0; w<width; w++){
            if(h!=0 && w!=0 && h!=width-1 && w!=height-1){
                unsigned tempValue=rand()%11;
                if(tempValue==0)
                    mappaBase[h][w]=tempValue;
                else mappaBase[h][w]=1;
            }
        }
    }
}

void createArea(int originX, int originY, int sizeX, int sizeY, char tileType){
    
    if(originY+sizeY>dimMapy-1)
        sizeY=dimMapy-1-originY;
    if(originX+sizeX>dimMapx-1)
        sizeX=dimMapx-1-originX;
    
    for(int h=originY; h<originY+sizeY; h++){
        for(int w=originX; w<originX+sizeX; w++){
            switch (tileType) {
                case 's':
                    baseMap[h][w]=2;
                    break;
                    
                case 'r':
                    baseMap[h][w]=3;
                    break;
                case 'a':
                    baseMap[h][w]=4;
                    break;
                    case 'b':
                    baseMap[h][w]=5;
                    break;
                    
                default:
                    break;
            }
        }
    }
}
#endif /* Maps_hpp */

/*
 const int baseMap [dimMapx][dimMapy]={
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 0},
 {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 0},
 {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 0},
 {0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 0},
 {0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
 {0, 0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
 };
 
 */






/*
 
 cicli per variazione tile a blocchi
 
 for(int i=dimMapx/2; i<dimMapx-1; i++){
 for(int j=dimMapy/2; j<dimMapy-1; j++){
 baseMap[i][j]=2;
 }
 }
 
 for(int i=1; i<dimMapx/2; i++){
 for(int j=1; j<dimMapy/2; j++){
 baseMap[i][j]=3;
 }
 }
 
 */
