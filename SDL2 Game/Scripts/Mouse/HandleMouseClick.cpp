//
//  HandleMouseClick.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-01.
//

#include "HandleMouseClick.hpp"



bool handleTileClickandEndTurn(SDL_Event* e, SDL_Rect camera )
{
    bool endturn = false;
    //If mouse event happened
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        //Only run if something is selected
        if(cardSelected != -1){
            //Get mouse position
            int x, y;
            SDL_GetMouseState( &x, &y );
            //check if clicked on UI
            if(x>uiConstants::XCardPadding){
                
                int toTileX =screenTotileX(x + camera.x);
                int toTileY = screenTotileY(y + camera.y);
                
                if(!buildingExistsAt(toTileX, toTileY) && allowedTileExistsAt(toTileX, toTileY)){
                    if(!getAllowedTileAt(toTileX, toTileY)->blocked && getAllowedTileAt(toTileX, toTileY)->active){
                        addBuildingAt(toTileX, toTileY, cardSelected);
                        
                        endturn = true;
  
                    }
                }
            }
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
    return endturn;
}
