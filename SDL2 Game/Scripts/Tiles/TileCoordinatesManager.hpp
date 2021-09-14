//
//  TileCoordinatesManager.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-01.
//

#ifndef TileCoordinatesManager_hpp
#define TileCoordinatesManager_hpp

#include <stdio.h>
#include "Constants.hpp"

//Gets Screen Coordinates From Tile Coordinates (X)
int tileToscreenX(int Xtile);

//Gets Screen Coordinates From Tile Coordinates (Y)
int tileToscreenY(int Ytile);

//Gets Tile Coordinates From Screen Coordinates (X)
int screenTotileX(int x);

//Gets Tile Coordinates From Screen Coordinates (Y)
int screenTotileY(int y);

#endif /* TileCoordinatesManager_hpp */
