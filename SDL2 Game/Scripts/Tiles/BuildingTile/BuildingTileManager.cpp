//
//  BuildingTileManager.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-07-02.
//

#include "BuildingTileManager.hpp"

BuildingTile::BuildingTile(int x, int y, int buildingType): tileItIs(x,y) {
     
    BaseType = buildingType;
    controllingFaction = tileConstants::NOT_CONTROLLED;
    
    if(buildingType == tileConstants::RESIDENTIAL_BUILDING){
        
        //Where it can be connected to
        topConnected = residentialConstants::topConnected;
        bottomConnected = residentialConstants::bottomConnected;
        rightConnected = residentialConstants::rightConnected;
        leftConnected = residentialConstants::leftConnected;
        
        //Base Yield
        Yeconomic = residentialConstants::Yeconomic;
        Yscience = residentialConstants::Yscience;
        Ylore = residentialConstants::Ylore;
        Yreligion = residentialConstants::Yreligion;
        Yfood = residentialConstants::Yfood;
        
        pop = residentialConstants::pop;
    }
    
    if(buildingType == tileConstants::ECONOMIC_BUILDING){
        
        //Where it can be connected to
        topConnected = economicConstants::topConnected;
        bottomConnected = economicConstants::bottomConnected;
        rightConnected = economicConstants::rightConnected;
        leftConnected = economicConstants::leftConnected;
        
        //Base Yield
        Yeconomic = economicConstants::Yeconomic;
        Yscience = economicConstants::Yscience;
        Ylore = economicConstants::Ylore;
        Yreligion = economicConstants::Yreligion;
        Yfood = economicConstants::Yfood;
        
        pop = economicConstants::pop;
    }
    
    if(buildingType == tileConstants::SCIENCE_BUILDING){
        
        //Where it can be connected to
        topConnected = scienceConstants::topConnected;
        bottomConnected = scienceConstants::bottomConnected;
        rightConnected = scienceConstants::rightConnected;
        leftConnected = scienceConstants::leftConnected;
        
        //Base Yield
        Yeconomic = scienceConstants::Yeconomic;
        Yscience = scienceConstants::Yscience;
        Ylore = scienceConstants::Ylore;
        Yreligion = scienceConstants::Yreligion;
        Yfood = scienceConstants::Yfood;
        
        pop = scienceConstants::pop;
    }
    
    if(buildingType == tileConstants::LORE_BUILDING){
        
        //Where it can be connected to
        topConnected = loreConstants::topConnected;
        bottomConnected = loreConstants::bottomConnected;
        rightConnected = loreConstants::rightConnected;
        leftConnected = loreConstants::leftConnected;
        
        //Base Yield
        Yeconomic = loreConstants::Yeconomic;
        Yscience = loreConstants::Yscience;
        Ylore = loreConstants::Ylore;
        Yreligion = loreConstants::Yreligion;
        Yfood = loreConstants::Yfood;
        
        pop = loreConstants::pop;
    }
    
    if(buildingType == tileConstants::RELIGION_BUILDING){
        
        //Where it can be connected to
        topConnected = religionConstants::topConnected;
        bottomConnected = religionConstants::bottomConnected;
        rightConnected = religionConstants::rightConnected;
        leftConnected = religionConstants::leftConnected;
        
        //Base Yield
        Yeconomic = religionConstants::Yeconomic;
        Yscience = religionConstants::Yscience;
        Ylore = religionConstants::Ylore;
        Yreligion = religionConstants::Yreligion;
        Yfood = religionConstants::Yfood;
        
        pop = religionConstants::pop;
    }
    
}

void BuildingTile::renderBuilding(SDL_Renderer *gRenderer, SDL_Rect& camera){
    tileItIs.render( gRenderer , camera, gTileTextures[BaseType+controllingFaction]);
    
}
