//
//  CardsInitLoader.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-07.
//

#ifndef CardsInitLoader_hpp
#define CardsInitLoader_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <fstream>
#include <vector>
#include "TextureManager.hpp"
#include "Constants.hpp"

extern LTexture gCardTextures[];
bool loadCards(SDL_Renderer* gRenderer);

#endif /* CardsInitLoader_hpp */
