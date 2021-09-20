//
//  TileInitLoader.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-06-30.
//

#include "TileInitLoader.hpp"

LTexture gTileTextures[tileConstants::TOTAL_TILE_SPRITES];

bool loadTiles(SDL_Renderer* gRenderer)
{
    //success flag
    bool success = true;



    //Load tile texture
    if( !gTileTextures[tileConstants::RESIDENTIAL_BUILDING].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Residential/Residential_neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RESIDENTIAL_BUILDING + tileConstants::ECONOMIC_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Residential/Residential_yellow.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RESIDENTIAL_BUILDING + tileConstants::SCIENCE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Residential/Residential_blue.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RESIDENTIAL_BUILDING + tileConstants::LORE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Residential/Residential_red.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RESIDENTIAL_BUILDING + tileConstants::RELIGION_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Residential/Residential_purple.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RESIDENTIAL_BUILDING + tileConstants::REBEL_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Residential/Residential_rebel.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    //ECONOMIC BUILDING
    if( !gTileTextures[tileConstants::ECONOMIC_BUILDING].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Economic/Market_Neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::ECONOMIC_BUILDING + tileConstants::ECONOMIC_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Economic/Market_Yellow.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::ECONOMIC_BUILDING + tileConstants::SCIENCE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Economic/Market_Blue.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::ECONOMIC_BUILDING + tileConstants::LORE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Economic/Market_Red.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::ECONOMIC_BUILDING + tileConstants::RELIGION_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Economic/Market_Purple.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::ECONOMIC_BUILDING + tileConstants::REBEL_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Economic/Market_rebel.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    //SCIENCE BUILDING
    if( !gTileTextures[tileConstants::SCIENCE_BUILDING].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Science/Library_Neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::SCIENCE_BUILDING + tileConstants::ECONOMIC_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Science/Library_Yellow.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::SCIENCE_BUILDING + tileConstants::SCIENCE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Science/Library_Blue.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::SCIENCE_BUILDING + tileConstants::LORE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Science/Library_Red.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::SCIENCE_BUILDING + tileConstants::RELIGION_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Science/Library_Purple.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::SCIENCE_BUILDING + tileConstants::REBEL_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Science/Library_rebel.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    //LORE BUILDING
    if( !gTileTextures[tileConstants::LORE_BUILDING].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Lore/Museum_neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::LORE_BUILDING + tileConstants::ECONOMIC_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Lore/Museum_yellow.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::LORE_BUILDING + tileConstants::SCIENCE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Lore/Museum_blue.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::LORE_BUILDING + tileConstants::LORE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Lore/Museum_red.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::LORE_BUILDING + tileConstants::RELIGION_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Lore/Museum_purple.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::LORE_BUILDING + tileConstants::REBEL_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Lore/Museum_rebel.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    //RELIGION BUILDING
    if( !gTileTextures[tileConstants::RELIGION_BUILDING].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Religion/Temple_Neutral.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RELIGION_BUILDING + tileConstants::ECONOMIC_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Religion/Temple_Yellow.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RELIGION_BUILDING + tileConstants::SCIENCE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Religion/Temple_Blue.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RELIGION_BUILDING + tileConstants::LORE_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Religion/Temple_Red.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RELIGION_BUILDING + tileConstants::RELIGION_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Religion/Temple_Purple.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::RELIGION_BUILDING + tileConstants::REBEL_CONTROLLED].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/Religion/Temple_rebel.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    
    
    //UI TEXTURES
    if( !gTileTextures[tileConstants::ALLOWED_TILE].loadFromFile(gRenderer, "PATHTO/Tiles/UI/AllowedTile.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }
    
    if( !gTileTextures[tileConstants::BLOCKED_TILE].loadFromFile(gRenderer, "PATHTO/Assets/Tiles/UI/BlockedTile.png" ) )
    {
        printf( "Failed to load texture!\n" );
        success = false;
    }

   

    return success;
}

