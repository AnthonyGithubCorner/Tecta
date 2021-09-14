//
//  TileLogic.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-03.
//

#include "TileLogic.hpp"

std::vector<BuildingTile*> buildingTileSet;

//Map gives the index of the building tile at the coordinate point (pair<int,int>) in the above vector
std::map<std::pair<int, int>, int> buildingTileIndex;

std::vector<AllowedTile*> allowedTileSet;

//Map gives the index of the allowed tile at the coordinate point (pair<int,int>) in the above vector
std::map<std::pair<int, int>, int> allowedTileIndex;



BuildingTile* getBuildingAt(int x, int y){
    int index = buildingTileIndex.at({x,y});
    return buildingTileSet[index];
}

bool buildingExistsAt(int x, int y){
    return (buildingTileIndex.count({x,y}) > 0);
}

void addBuildingAt(int x, int y, int buildingType){
//    if((x<0 || y<0)){
//        return;
//    }
//
//    if((x>screenTotileX(dimensionConstants::LEVEL_WIDTH )|| y>screenTotileY(dimensionConstants::LEVEL_HEIGHT))){
//        return;
//    }
    if(allowedTileExistsAt(x, y)){
        removeAllowedTile(x, y);
    }
    BuildingTile* newTile = new BuildingTile( x, y, buildingType ) ;
    buildingTileSet.push_back(newTile);
    buildingTileIndex[{x,y}] = buildingTileSet.size()-1;
    
    if (newTile->topConnected)
    {
        printf("top");
        addOpening(x, y-1, directionalConstants::TOP);
    }
    if (newTile->bottomConnected)
    {
        printf("bottom");
        addOpening(x, y+1, directionalConstants::BOTTOM);
    }
    if (newTile->rightConnected)
    {
        printf("right");

        addOpening(x+1, y, directionalConstants::RIGHT);
    }
    if (newTile->leftConnected)
    {
        printf("left");
        addOpening(x-1, y, directionalConstants::LEFT);
    }
    printf("Thats all \n\n");
}

//Allowed Tiles
AllowedTile* getAllowedTileAt(int x, int y){
    int index = allowedTileIndex.at({x,y});
    return allowedTileSet[index];
}

bool allowedTileExistsAt(int x, int y){
    return (allowedTileIndex.count({x,y}) > 0);
}

void addAllowedTileAt(int x, int y){

    AllowedTile* newTile = new AllowedTile(x, y);
    if((x<0 || y<0)){
        newTile->active = false;
    }
    
    if((x>=screenTotileX(dimensionConstants::LEVEL_WIDTH ) || y>=screenTotileY(dimensionConstants::LEVEL_HEIGHT))){
        newTile->active = false;
    }
    allowedTileSet.push_back(newTile);
    allowedTileIndex[{x,y}] = allowedTileSet.size()-1;

    
}

void addOpening(int x, int y, int direction){
    
    if (!buildingExistsAt(x, y) && !allowedTileExistsAt(x,y))
    {
        printf(" added ");
        addAllowedTileAt(x, y);
    }
    if(!buildingExistsAt(x,y)){
        AllowedTile* toChange;
        toChange = getAllowedTileAt(x, y);
        if (direction == directionalConstants::TOP)
        {
            toChange->OpenBottom = true;
        }
        
        if (direction == directionalConstants::BOTTOM)
        {
            toChange->OpenTop = true;
        }
        
        if (direction == directionalConstants::RIGHT)
        {
            toChange->OpenLeft = true;
        }
        
        if (direction == directionalConstants::LEFT)
        {
            toChange->OpenRight = true;
        }
    }
}

void removeAllowedTile(int x, int y){
    getAllowedTileAt(x, y)->active = false;
    allowedTileIndex.erase({x,y});
    
}

