//
//  CameraMouse.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-01.
//

#include "CameraMouse.hpp"

void CameraMouse(SDL_Rect& camera )
{
    
    //Get mouse position
    int x, y;
    SDL_GetMouseState( &x, &y );
    
    if(x > camera.w - cameraConstants::XEDGE  ){
        camera.x += cameraConstants::XSCROLLSPEED;
    }
    if(x < cameraConstants::XEDGE  ){
        camera.x -= cameraConstants::XSCROLLSPEED;
    }
    if(y > camera.h - cameraConstants::YEDGE  ){
        camera.y += cameraConstants::YSCROLLSPEED;
        
    }
    if(y <  cameraConstants::YEDGE  ){
        camera.y -= cameraConstants::YSCROLLSPEED;
    }
    
    //Keep the camera in bounds
    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > dimensionConstants::LEVEL_WIDTH - camera.w )
    {
        camera.x = dimensionConstants::LEVEL_WIDTH - camera.w;
    }
    if( camera.y > dimensionConstants::LEVEL_HEIGHT - camera.h )
    {
        camera.y = dimensionConstants::LEVEL_HEIGHT - camera.h;
    }
    
}
