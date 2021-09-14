//
//  TileInitLoader.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-06-30.
//

#ifndef TileInitLoader_hpp
#define TileInitLoader_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <fstream>
#include <vector>
#include "TileManager.hpp"
#include "TextureManager.hpp"
#include "Constants.hpp"

extern LTexture gTileTextures[];
bool loadTiles(SDL_Renderer* gRenderer);

#endif /* TileInitLoader_hpp */
