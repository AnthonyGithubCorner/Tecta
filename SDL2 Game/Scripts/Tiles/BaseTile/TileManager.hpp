//
//  TileManager.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-06-30.
//

#ifndef TileManager_hpp
#define TileManager_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include "Constants.hpp"
#include "TileCoordinatesManager.hpp"
#include "CameraCollision.hpp"


//The base tile should never be accessed directly
class TileBase
{
public:
    //Initializes position and type
    TileBase( int x, int y);
    
    //Shows the tile
    void render( SDL_Renderer *gRenderer, SDL_Rect& camera, LTexture& tileTexture);
    
    
    int Xtile;
    
    int Ytile;


};



#endif /* TileManager_hpp */
