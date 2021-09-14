//
//  CardSelect.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-03.
//

#include "CardSelect.hpp"
int option1;
int option2;
int option3;
int cardSelected = 0;

int Noptions = tileConstants::ECONOMIC_BUILDING;

void createCards(SDL_Renderer *gRenderer){
    
    gCardTextures[option1].render(gRenderer, uiConstants::xOffset, 20);
    gCardTextures[option2].render(gRenderer, uiConstants::xOffset, 150);
    gCardTextures[option3].render(gRenderer, uiConstants::xOffset, 300);
    
}

//used by tile select to reset cards
void resetCards(){
    option1 = rand() % cardConstants::TOTAL_CARDS;
    option2 = rand() % cardConstants::TOTAL_CARDS;
    while ( option1 == option2){
        option2 = rand() % cardConstants::TOTAL_CARDS;
    }
    option3 = rand() % cardConstants::TOTAL_CARDS;
    while(option1 == option3 || option2 == option3){
        option3 = rand() % cardConstants::TOTAL_CARDS;
    }
}
void handleCardClick(SDL_Event* e, SDL_Rect camera)
{
    //If mouse event happened
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        
        if(x<=100){
            if(y>=20 && y<=120){
                cardSelected = option1*Noptions;
            }
            if(y>=150 && y<=250){
                cardSelected = option2*Noptions;
            }
            if(y>=300 && y<=400){
                cardSelected = option3*Noptions;
            }
            
            CheckGameOver(option1, option2, option3);
            CheckAllowedTiles(cardSelected);
        }
        

        
        //        else{
        //            int currentF = getBuildingAt(toTileX, toTileY)->controllingFaction;
        //            if(currentF == 0){
        //                getBuildingAt(toTileX, toTileY)->controllingFaction = 1;
        //            }
        //            if(currentF == 1){
        //                getBuildingAt(toTileX, toTileY)->controllingFaction = 0;
        //            }
        //        }
        
    }
}
