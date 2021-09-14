//
//  AllowedTileManager.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-03.
//

#include "AllowedTileManager.hpp"

AllowedTile::AllowedTile(int x, int y) : tileItIs(x,y){
    active = true;
    
    blocked = false;
    
    OpenTop = false;
    OpenBottom = false;
    OpenRight = false;
    OpenLeft = false;
    

}

void AllowedTile::renderAllowedTile(SDL_Renderer *gRenderer, SDL_Rect &camera){
    tileItIs.render( gRenderer , camera, gTileTextures[tileConstants::ALLOWED_TILE]);
}

void AllowedTile::renderBlockedTile(SDL_Renderer *gRenderer, SDL_Rect &camera){
    tileItIs.render( gRenderer , camera, gTileTextures[tileConstants::BLOCKED_TILE]);
}
