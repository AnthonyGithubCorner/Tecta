//
//  TileCoordinatesManager.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-01.
//

#include "TileCoordinatesManager.hpp"

int tileToscreenX(int Xtile){
    return uiConstants::XCardPadding+(tileConstants::TILE_WIDTH*Xtile);
}

int tileToscreenY(int Ytile){
    return tileConstants::TILE_HEIGHT*Ytile;
}

int screenTotileX(int x){
    return (x/tileConstants::TILE_WIDTH) - (uiConstants::XCardPadding/tileConstants::TILE_WIDTH);
}

int screenTotileY(int y){
    return y/tileConstants::TILE_HEIGHT;
}
