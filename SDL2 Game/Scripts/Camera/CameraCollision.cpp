//
//  CameraCollision.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-01.
//

#include "CameraCollision.hpp"

//used to see if tile should render
bool checkToRender( SDL_Rect camera, int x, int y )
{
    //The sides of the tile
    int left1, right1, top1, bottom1;
    int left2, right2, top2, bottom2;
    
    //Calculate the dimensions of Tile
    left1 = x;
    right1 = x + tileConstants::TILE_WIDTH;
    top1 = y;
    bottom1 = y + tileConstants::TILE_HEIGHT;
    
    //Calculate the dimensions of camera
    left2 = camera.x;
    right2 = camera.x + camera.w;
    top2 = camera.y;
    bottom2 = camera.y + camera.h;
    
    //If tile is not in camera
    if( bottom1 <= top2 || top1 >= bottom2 || right1 <= left2 || left1 >= right2 )
    {
        return false;
    }
    
    //tile must than be in camera and rendered
    return true;
}
