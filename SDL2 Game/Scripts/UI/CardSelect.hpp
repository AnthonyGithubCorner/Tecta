//
//  CardSelect.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-03.
//

#ifndef CardSelect_hpp
#define CardSelect_hpp

#include <stdio.h>
#include "TileLogic.hpp"
#include "HandleMouseClick.hpp"
#include "CheckAllowedTiles.hpp"
#include "CheckGameOver.hpp"
#include "CardsInitLoader.hpp"


void createCards(SDL_Renderer *gRenderer);
void handleCardClick(SDL_Event* e, SDL_Rect camera);
void resetCards();

extern int cardSelected;
#endif /* CardSelect_hpp */
