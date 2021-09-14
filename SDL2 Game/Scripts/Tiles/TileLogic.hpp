//
//  TileLogic.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-03.
//


#ifndef TileLogic_hpp
#define TileLogic_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include "BuildingTileManager.hpp"
#include "AllowedTileManager.hpp"

//
//Serves as a congergation of all the tile code built so far. Functions to be used in virtually all code concerning tiles.
//

//Contains all buildings in use
extern std::vector<BuildingTile*> buildingTileSet;


//Gets Building at specified coordinate point
BuildingTile* getBuildingAt(int x, int y);

//Checks if building tile exists at point
bool buildingExistsAt(int x, int y);

void addBuildingAt(int x, int y, int buildingType);

//Allowed Tiles

//Contains all allowed tiles in use
extern std::vector<AllowedTile*> allowedTileSet;



//Gets Building at specified coordinate point
AllowedTile* getAllowedTileAt(int x, int y);

bool allowedTileExistsAt(int x, int y);

void addAllowedTileAt(int x, int y);

void addOpening(int x, int y, int direction);

void removeAllowedTile(int x, int y);

#endif /* TileLogic_hpp */
