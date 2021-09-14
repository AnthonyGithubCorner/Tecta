//
//  YieldLogic.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-09-10.
//

#include "YieldLogic.hpp"



void renderYieldText(SDL_Renderer *gRenderer, TTF_Font* yieldFont){
    SDL_Color Black = {0,0,0};
    int scienceR = 0;
    int economicR = 0;
    int loreR = 0;
    int religionR = 0;
    int foodR = 0;
     factionRequirments(&scienceR, &economicR, &loreR, &religionR, &foodR);
    std::string UItoPrint = "Total Science: " + std::to_string(totalScience()) + "/" + std::to_string(scienceR) + "\t\t\t\t\t\tTotal Economy: " + std::to_string(totalEconomic())+ "/" + std::to_string(economicR) + "\t\t\t\t\t\tTotal Lore: " + std::to_string(totalLore()) + "/" + std::to_string(loreR);
    
    std::string UItoPrint2 = "Total Religion: " + std::to_string(totalReligion()) + "/" + std::to_string(religionR) + "\t\t\t\t\t\tTotal Food: " + std::to_string(totalFood())+ "/" +  std::to_string(foodR);
    
    
    SDL_Surface* message = TTF_RenderText_Solid(yieldFont, UItoPrint.c_str(), Black);
    SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(gRenderer, message);
    
    //get width and height of message
    int w;
    int h;
    TTF_SizeText(yieldFont, UItoPrint.c_str(), &w, &h);
    SDL_Rect renderQuad = {uiConstants::xOffset,dimensionConstants::SCREEN_HEIGHT-50, w, h};
    SDL_RenderCopy( gRenderer, messageTexture, NULL, &renderQuad );
    
    SDL_Surface* message2 = TTF_RenderText_Solid(yieldFont, UItoPrint2.c_str(), Black);
    SDL_Texture* messageTexture2 = SDL_CreateTextureFromSurface(gRenderer, message2);
    TTF_SizeText(yieldFont, UItoPrint2.c_str(), &w, &h);
    SDL_Rect renderQuad2 = {uiConstants::xOffset,dimensionConstants::SCREEN_HEIGHT-20, w, h};
    SDL_RenderCopy( gRenderer, messageTexture2, NULL, &renderQuad2 );
}

