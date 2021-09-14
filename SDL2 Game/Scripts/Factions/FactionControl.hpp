//
//  FactionControl.hpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-09-11.
//

#ifndef FactionControl_hpp
#define FactionControl_hpp

#include <stdio.h>
#include "TileLogic.hpp"


void factionSpread();
void factionRequirments(int* scienceR, int* economicR, int* loreR, int* religionR, int* foodR);
int totalPop();
int totalScience();
int totalEconomic();
int totalLore();
int totalReligion();
int totalFood();
#endif /* FactionControl_hpp */
