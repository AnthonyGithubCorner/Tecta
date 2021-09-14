//Using SDL, SDL_image, maps, IO, strings, file reading, vectors
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <map>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

//Include other files
#include "TextureManager.hpp"
#include "Constants.hpp"
#include "CameraMouse.hpp"
#include "HandleMouseClick.hpp"
#include "TileLogic.hpp"
#include "CardSelect.hpp"
#include "CheckGameOver.hpp"
#include "YieldLogic.hpp"






//Starts up SDL and creates window
bool init();

//Frees up memory and closes program
void close( std::vector<BuildingTile*> tileSet, std::vector<AllowedTile*> tileSet2 );

//The window to render to
SDL_Window* gWindow = NULL;

//The renderer
SDL_Renderer* gRenderer = NULL;

//font
TTF_Font *yieldFont;

//used to endtrun
void endturn(){
    //reset selection
    cardSelected = -1;
    
    //show all possible placements (residential building as no restrictions)
    CheckAllowedTiles(0);
    
    //resets cards to choose
    resetCards();
    
    //spread faction
    factionSpread();
}

//used to close game or reset
void deallocatetiles(std::vector<BuildingTile*> tileSet, std::vector<AllowedTile*> tileSet2){
    //Deallocate tiles
    for( auto q : tileSet)
    {
        if(q!=NULL){
            delete q;
        }
    }
    
    for( auto q : tileSet2)
    {
        if(q!=NULL){
            delete q;
        }
    }
}

//used at start of game to place initial position
void startGame(SDL_Rect camera){
    //Level camera
    camera = { 0, 0, dimensionConstants::SCREEN_WIDTH, dimensionConstants::SCREEN_HEIGHT };
    
    //Set starting build space
    int originalTileX = screenTotileX(dimensionConstants::SCREEN_WIDTH/2);
    int orginalTileY = screenTotileY(dimensionConstants::SCREEN_HEIGHT/2);
    addAllowedTileAt(originalTileX, orginalTileY);
    addOpening(originalTileX, orginalTileY, directionalConstants::TOP);
    addOpening(originalTileX, orginalTileY, directionalConstants::BOTTOM);
    addOpening(originalTileX, orginalTileY, directionalConstants::RIGHT);
    addOpening(originalTileX, orginalTileY, directionalConstants::LEFT);
}

bool init()
{
    //success flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    
    //Create window
    gWindow = SDL_CreateWindow( "Tecta", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dimensionConstants::SCREEN_WIDTH, dimensionConstants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    
    //Fill Screen With Chosen color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    IMG_Init( imgFlags );
    
    //load textures
    loadTiles(gRenderer);
    loadCards(gRenderer);
    
    //Initialize SDL_tff for rendering text
    TTF_Init();
    
    //load fonts
    //Yield font
    yieldFont = TTF_OpenFont("/Users/anthony/C++Projects/SDL2 Game/SDL2 Game/Assets/UI/fonts/Herculanum.ttf", uiConstants::fontSize);
    
    return success;
}


void close( std::vector<BuildingTile*> tileSet, std::vector<AllowedTile*> tileSet2 )
{
    
    deallocatetiles(tileSet, tileSet2);
    //Free loaded textures
    for( int i = 0; i < tileConstants::TOTAL_TILE_SPRITES; ++i )
    {
        gTileTextures[i].free();
    }
    
    for( int i = 0; i < cardConstants::TOTAL_CARDS; ++i )
    {
        gCardTextures[i].free();
    }
    
    //free font
    TTF_CloseFont(yieldFont);
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}



int main( int argc, char* args[] )
{
    init();
    SDL_Rect camera = { 0, 0, dimensionConstants::SCREEN_WIDTH, dimensionConstants::SCREEN_HEIGHT };
    
    startGame(camera);
    
    //Main loop flag
    bool quit = false;
    
    //Event handler
    SDL_Event e;
    
    
    
    //While application is running
    while( !quit )
    {
        if(gameState == 0){
            CameraMouse(camera);
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
                //                    if( e.type == SDL_KEYDOWN )
                //                    {
                //                        if(e.key.keysym.sym == SDLK_a){
                //                            buildingTileSet[0]->controllingFaction=tileConstants::ECONOMIC_CONTROLLED;
                //                            printf("changed");
                //                        }
                //                        if(e.key.keysym.sym == SDLK_s){
                //                            buildingTileSet[0]->controllingFaction=tileConstants::NOT_CONTROLLED;
                //                            printf("changed");
                //                        }
                //                    }
                handleCardClick(&e, camera);
                
                //if valid tile placements places tile and ends turn
                if(handleTileClickandEndTurn(&e, camera)){
                    
                    //end turn
                    endturn();
                    
                }
                
                
                
            }
            
            
            //Clear screen
            
            //Set to Ocean Blue
            SDL_SetRenderDrawColor( gRenderer, 0, 64, 128, 255 );
            SDL_RenderClear( gRenderer );
            
            //Render level
            for( auto q: buildingTileSet )
            {
                q->renderBuilding(gRenderer, camera);
            }
            for( auto q: allowedTileSet )
            {
                if(q->active == true){
                    if(q->blocked == false){
                        q->renderAllowedTile(gRenderer, camera);
                    }
                    else{
                        q->renderBlockedTile(gRenderer, camera);
                    }
                }
            }
            
            //Set UI area color
            SDL_SetRenderDrawColor( gRenderer, 121, 86, 86, 255 );
            
            //set box on cards
            SDL_Rect UICardR = {0,0, uiConstants::XCardPadding, dimensionConstants::SCREEN_HEIGHT};
            SDL_RenderFillRect(gRenderer, &UICardR);
            
            SDL_SetRenderDrawColor( gRenderer, 161, 120, 92, 255 );
            //set box on text
            SDL_Rect UITextR = {0,dimensionConstants::SCREEN_HEIGHT-uiConstants::YCardPadding, dimensionConstants::SCREEN_WIDTH, dimensionConstants::SCREEN_HEIGHT};
            SDL_RenderFillRect(gRenderer, &UITextR);
            
            
            
            //Render Cards/UI
            createCards(gRenderer);
            
            //render textUI
            renderYieldText(gRenderer, yieldFont);
            
            
            
            //Update screen
            SDL_RenderPresent( gRenderer );
        }
        else{
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
//                if( e.type == SDL_MOUSEBUTTONDOWN )
//                {
//
//                    //reset game
//                    gameState = 1;
//
//                    //erase past tiles in memory
//                    deallocatetiles(buildingTileSet, allowedTileSet);
//
//                    //reset starting position with new tiles
//                    startGame(camera);
//
//
//                }
            }
            //print gameover screen
            SDL_SetRenderDrawColor( gRenderer, 0, 64, 128, 255 );
            SDL_RenderClear( gRenderer );
            
            //print score
            std::string UItoPrint = "GameOver! Your Empire Had : " + std::to_string(totalPop()) + " People!";
            SDL_Color Black = {0,0,0};
            SDL_Surface* message = TTF_RenderText_Solid(yieldFont, UItoPrint.c_str(), Black);
            SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(gRenderer, message);
            
            
            //get width and height of message
            int w;
            int h;
            TTF_SizeText(yieldFont, UItoPrint.c_str(), &w, &h);
            SDL_Rect renderQuad = {dimensionConstants::SCREEN_HEIGHT/2 - 30,dimensionConstants::SCREEN_HEIGHT/2 -50, w, h};
            SDL_RenderCopy( gRenderer, messageTexture, NULL, &renderQuad );
            
            //print try again instructions
            std::string UItoPrint2 = "Close and Open Game to try again";;
            SDL_Surface* message2 = TTF_RenderText_Solid(yieldFont, UItoPrint2.c_str(), Black);
            SDL_Texture* messageTexture2 = SDL_CreateTextureFromSurface(gRenderer, message2);
            
            
            //get width and height of message
            TTF_SizeText(yieldFont, UItoPrint2.c_str(), &w, &h);
            SDL_Rect renderQuad2 = {dimensionConstants::SCREEN_HEIGHT/2 - 25,dimensionConstants::SCREEN_HEIGHT/2 -20, w, h};
            SDL_RenderCopy( gRenderer, messageTexture2, NULL, &renderQuad2 );
            
            //Update screen
            SDL_RenderPresent( gRenderer );
            
            
        }
        
        
    }
    //Free resources and close SDL
    close( buildingTileSet, allowedTileSet );
    
    return 0;
}
