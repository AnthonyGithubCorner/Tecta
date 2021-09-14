//
//  HandleMouseClick.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-01.
//

#ifndef HandleMouseClick_hpp
#define HandleMouseClick_hpp

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include "Constants.hpp"
#include "BuildingTileManager.hpp"
#include "TileLogic.hpp"
#include "CheckAllowedTiles.hpp"
#include "CardSelect.hpp"
#include "FactionControl.hpp"
#include "YieldLogic.hpp"

bool handleTileClickandEndTurn(SDL_Event* e, SDL_Rect camera );


#endif /* HandleMouseClick_hpp */
