//
//  Constants.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-06-30.
//

#ifndef Constants_hpp
#define Constants_hpp

namespace dimensionConstants
{
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The dimensions of the level
const int LEVEL_WIDTH = 1000;
const int LEVEL_HEIGHT = 1000;
}

namespace cameraConstants
{
//Camera constants
const int XEDGE = 20;
const int YEDGE = 100;
const int XSCROLLSPEED = 10;
const int YSCROLLSPEED = 10;
}

namespace uiConstants{

//UI Constants
const int XCardPadding = 160;
const int xOffset = 20;
const int YCardPadding = 60;
const int fontSize = 16;

}

namespace cardConstants{
//Card constants

const int TOTAL_CARDS = 5;

//Used to access textures
const int RESIDENTIAL_CARD = 0;
const int ECONOMIC_CARD = 1;
const int SCIENCE_CARD = 2;
const int LORE_CARD = 3;
const int RELIGION_CARD = 4;


}

namespace tileConstants
{
//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILE_SPRITES = 33;


//Building Textures
const int RESIDENTIAL_BUILDING = 0;
const int ECONOMIC_BUILDING = 6;
const int SCIENCE_BUILDING = 12;
const int LORE_BUILDING = 18;
const int RELIGION_BUILDING = 24;

//Faction Const set to avoid repetition
const int TOTAL_FACTIONS = 6;
const int NOT_CONTROLLED = 0;
const int ECONOMIC_CONTROLLED = 1;
const int SCIENCE_CONTROLLED = 2;
const int LORE_CONTROLLED = 3;
const int RELIGION_CONTROLLED = 4;
const int REBEL_CONTROLLED = 5;

//UI Tile Textures
const int ALLOWED_TILE = 30;
const int BLOCKED_TILE = 31;
const int POSSIBLE_TILE = 32;

}

namespace directionalConstants{
const int TOP = 0;
const int BOTTOM = 1;
const int RIGHT = 2;
const int LEFT = 3;

}




//
//Related to Base Building Stats, Useful for Balancing
//

namespace residentialConstants {

//Where it can be connected to
static bool topConnected = true;
static bool bottomConnected = true;
static bool rightConnected = true;
static bool leftConnected = true;

//Base Yield
static float Yeconomic = 0;
static float Yscience = 0;
static float Ylore = 0;
static float Yreligion = 0;
static float Yfood = 15;

//Amount of pop in the building
static int pop = 10;
}

namespace economicConstants {

//Where it can be connected to
static bool topConnected = true;
static bool bottomConnected = true;
static bool rightConnected = false;
static bool leftConnected = false;

//Base Yield
static float Yeconomic = 5;
static float Yscience = 0;
static float Ylore = 0;
static float Yreligion = 0;
static float Yfood = 0;

//Amount of pop in the building
static int pop = 3;
}

namespace scienceConstants {

//Where it can be connected to
static bool topConnected = true;
static bool bottomConnected = false;
static bool rightConnected = true;
static bool leftConnected = false;

//Base Yield
static float Yeconomic = 0;
static float Yscience = 5;
static float Ylore = 0;
static float Yreligion = 0;
static float Yfood = 0;

//Amount of pop in the building
static int pop = 3;
}

namespace loreConstants {

//Where it can be connected to
static bool topConnected = true;
static bool bottomConnected = true;
static bool rightConnected = false;
static bool leftConnected = false;

//Base Yield
static float Yeconomic = 0;
static float Yscience = 0;
static float Ylore = 5;
static float Yreligion = 0;
static float Yfood = 0;

//Amount of pop in the building
static int pop = 3;
}

namespace religionConstants {

//Where it can be connected to
static bool topConnected = true;
static bool bottomConnected = false;
static bool rightConnected = false;
static bool leftConnected = true;

//Base Yield
static float Yeconomic = 0;
static float Yscience = 0;
static float Ylore = 0;
static float Yreligion = 5;
static float Yfood = 0;

//Amount of pop in the building
static int pop = 3;
}



#endif /* Constants_hpp */
