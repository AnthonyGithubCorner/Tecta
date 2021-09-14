//
//  CheckAllowedTiles.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-04.
//

#include "CheckAllowedTiles.hpp"


//check if there is a rebel faction near the building
bool checkRebels(TileBase allowedTiletoCheck){
    if(buildingExistsAt(allowedTiletoCheck.Xtile + 1, allowedTiletoCheck.Ytile)){
        if(getBuildingAt(allowedTiletoCheck.Xtile + 1, allowedTiletoCheck.Ytile)->controllingFaction==tileConstants::REBEL_CONTROLLED){
            return true;
        }
    }
    if(buildingExistsAt(allowedTiletoCheck.Xtile - 1, allowedTiletoCheck.Ytile)){
        if(getBuildingAt(allowedTiletoCheck.Xtile - 1, allowedTiletoCheck.Ytile)->controllingFaction==tileConstants::REBEL_CONTROLLED){
            return true;
        }
    }
    if(buildingExistsAt(allowedTiletoCheck.Xtile, allowedTiletoCheck.Ytile+1)){
        if(getBuildingAt(allowedTiletoCheck.Xtile, allowedTiletoCheck.Ytile+1)->controllingFaction==tileConstants::REBEL_CONTROLLED){
            return true;
        }
    }
    if(buildingExistsAt(allowedTiletoCheck.Xtile, allowedTiletoCheck.Ytile-1)){
        if(getBuildingAt(allowedTiletoCheck.Xtile, allowedTiletoCheck.Ytile-1)->controllingFaction==tileConstants::REBEL_CONTROLLED){
            return true;
        }
    }
    return false;
    
}

int CheckAllowedTiles(int cardTypeToCheck){
    int i = 0;
    //creates reference
    BuildingTile* buildingToCheck = new BuildingTile(-10, -10, cardTypeToCheck);
    for(auto q: allowedTileSet){
        if(((buildingToCheck->topConnected && q->OpenTop)||(buildingToCheck->bottomConnected && q->OpenBottom)||(buildingToCheck->rightConnected && q->OpenRight)||(buildingToCheck->leftConnected && q->OpenLeft)) && (q->active == true) && (!checkRebels(q->tileItIs))){
            q->blocked = false;
            i++;
        }
        else{
            q->blocked = true;
        }
    }
    delete buildingToCheck;
    return i;
}
