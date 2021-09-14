//
//  CardsInitLoader.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-07.
//

#include "CardsInitLoader.hpp"

LTexture gCardTextures[cardConstants::TOTAL_CARDS];

bool loadCards(SDL_Renderer* gRenderer)
{
    //success flag
    bool success = true;



    //Load tile texture
    if( !gCardTextures[cardConstants::RESIDENTIAL_CARD].loadFromFile(gRenderer, "/Users/anthony/C++Projects/SDL2 Game/SDL2 Game/Assets/UI/Cards/Residential_neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gCardTextures[cardConstants::ECONOMIC_CARD].loadFromFile(gRenderer, "/Users/anthony/C++Projects/SDL2 Game/SDL2 Game/Assets/UI/Cards/Market_Neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !gCardTextures[cardConstants::SCIENCE_CARD].loadFromFile(gRenderer, "/Users/anthony/C++Projects/SDL2 Game/SDL2 Game/Assets/UI/Cards/Library_Neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !gCardTextures[cardConstants::LORE_CARD].loadFromFile(gRenderer, "/Users/anthony/C++Projects/SDL2 Game/SDL2 Game/Assets/UI/Cards/Museum_neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    if( !gCardTextures[cardConstants::RELIGION_CARD].loadFromFile(gRenderer, "/Users/anthony/C++Projects/SDL2 Game/SDL2 Game/Assets/UI/Cards/Temple_Neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }


   

    return success;
}
