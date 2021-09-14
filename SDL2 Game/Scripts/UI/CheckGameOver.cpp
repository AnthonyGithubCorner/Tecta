//
//  CheckGameOver.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-04.
//

#include "CheckGameOver.hpp"

int gameState = 0;

bool CheckGameOver(int option1, int option2, int option3){
    int i = 0;
    i += CheckAllowedTiles(option1);
    i += CheckAllowedTiles(option2);
    i += CheckAllowedTiles(option3);
    
    if(i==0){
        printf("GAMEOVER");
        gameState = 1;
        return true;
    }
    else{
        return false;
    }
    
};
