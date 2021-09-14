//
//  BuildingTileManager.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-02.
//

#ifndef BuildingTileManager_hpp
#define BuildingTileManager_hpp

#include <stdio.h>
#include <string.h>
#include "TileManager.hpp"
#include "TileInitLoader.hpp"
#include "Constants.hpp"


//Derivative of TileBase is accessed to create the main tiles
class BuildingTile
{
public:
    BuildingTile(int x, int y, int buildingType);
    
    //Tile that contains position and rendering method
    TileBase tileItIs;

    
    //Where it can be connected to
    bool topConnected=1;
    bool bottomConnected=1;
    bool rightConnected=1;
    bool leftConnected=1;
    
    //Base Yield
    float Yeconomic=0;
    float Yscience=0;
    float Ylore=0;
    float Yreligion=0;
    float Yfood=0;
    
    //Faction Multiplier
    float Meconomic=0;
    float Mscience=0;
    float Mlore=0;
    float Mreligion=0;
    float Mfood=0;
    
    //Faction Legacy Multiplier
    float Leconomic=0;
    float Lscience=0;
    float Llore=0;
    float Lreligion=0;
    float Lfood=0;
    
    //Resource Multiplier
    float Beconomic=0;
    float Bscience=0;
    float Blore=0;
    float Breligion=0;
    float Bfood=0;
    
    //Amount of pop in the building
    int pop = 0;
    
    
    //Used to identify textures
    int BaseType = 0;
    
    //Which Faction Currently Controls The Building (And the pop it contains);
    //Used with base type to identify textures;
    int controllingFaction = 0;
    
    std::string name;
    
    std::string description;
    
    std::vector<std::string> history;
    
    //Render (Communicates with tile render
    void renderBuilding(SDL_Renderer *gRenderer, SDL_Rect& camera);
    
};

#endif /* BuildingTileManager_hpp */
