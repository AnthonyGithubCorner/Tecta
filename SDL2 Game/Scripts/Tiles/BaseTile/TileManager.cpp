//
//  TileManager.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-06-30.
//

#include "TileManager.hpp"

TileBase::TileBase( int x, int y)
{
    Xtile = x;
    Ytile = y;

}

void TileBase::render( SDL_Renderer *gRenderer, SDL_Rect& camera,  LTexture& tileTexture )
{
    //If the tile is on screen
    int x = tileToscreenX(Xtile);
    int y = tileToscreenY(Ytile);
    if( checkToRender( camera, x, y) )
    {
        //Show the tile
        tileTexture.render( gRenderer, x - camera.x, y - camera.y);
    }
}


