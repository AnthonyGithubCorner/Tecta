//
//  AllowedTileManager.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-03.
//

#ifndef AllowedTileManager_hpp
#define AllowedTileManager_hpp

#include <stdio.h>
#include "TileManager.hpp"
#include "TileInitLoader.hpp"
#include "Constants.hpp"

//Derivative of TileBase is accessed to create the allowed tiles used to determine allowed spots to place
class AllowedTile
{
public:
    AllowedTile(int x, int y);
    
    //Tile that contains position and rendering method
    TileBase tileItIs;

    bool OpenTop;
    bool OpenBottom;
    bool OpenRight;
    bool OpenLeft;
    
    bool active;
    
    bool blocked;
    //Render (Communicates with tile render)
    void renderAllowedTile(SDL_Renderer *gRenderer, SDL_Rect& camera);
    void renderBlockedTile(SDL_Renderer *gRenderer, SDL_Rect& camera);
    
};
#endif /* AllowedTileManager_hpp */
