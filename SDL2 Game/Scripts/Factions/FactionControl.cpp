//
//  FactionControl.cpp
//  SDL2 Game
//
//  Created by Anthony Lazar on 2021-09-11.
//

#include "FactionControl.hpp"

int totalPop(){
    int sum = 0;
    for( auto q: buildingTileSet )
    {
        sum+=q->pop;
        
    }
    return sum;
}
int totalScience(){
    int sum = 0;
    for( auto q: buildingTileSet )
    {
        sum+=q->Yscience;
    }
    return sum;
}

int totalFood(){
    int sum = 0;
    for( auto q: buildingTileSet )
    {
        sum+=q->Yfood;
    }
    return sum;
}

int totalLore(){
    int sum = 0;
    for( auto q: buildingTileSet )
    {
        sum+=q->Ylore;
    }
    return sum;
}

int totalEconomic(){
    int sum = 0;
    for( auto q: buildingTileSet )
    {
        sum+=q->Yeconomic;
    }
    return sum;
}

int totalReligion(){
    int sum = 0;
    for( auto q: buildingTileSet )
    {
        sum+=q->Yreligion;
    }
    return sum;
}

int rebelChance(){
    int chance = 0;
    int scienceR = 0;
    int economicR = 0;
    int loreR = 0;
    int religionR = 0;
    int foodR = 0;
    factionRequirments(&scienceR, &economicR, &loreR, &religionR, &foodR);
    if(scienceR>totalScience()){
        chance += scienceR-totalScience();
    }
    if(economicR>totalEconomic()){
        chance += economicR-totalEconomic();
    }
    if(loreR>totalLore()){
        chance += loreR-totalLore();
    }
    if(religionR>totalReligion()){
        chance += religionR-totalReligion();
    }
    if(foodR>totalFood()){
        chance += foodR-totalFood();
    }
    return chance;
}


void factionSpawn(){
    int randSpawn = rand() % (5);

    int randFaction = rand() % (tileConstants::TOTAL_FACTIONS-1);
    if (rebelChance()>15){
        randFaction = tileConstants::REBEL_CONTROLLED;
        randSpawn = 0;
    }
    if (randSpawn < 1 && buildingTileSet.size()>1){
        int randTile = rand() % (buildingTileSet.size()-1);
        buildingTileSet[randTile]->controllingFaction = randFaction;
        printf("spawn! by %d at %d\n", randFaction, randTile);
    }
}

void factionfight(int toCheckX, int toCheckY, BuildingTile* factionAttacking)
{
    if (buildingExistsAt(toCheckX, toCheckY)){
        
        BuildingTile* factionDefending = getBuildingAt(toCheckX, toCheckY);
        if(factionDefending->controllingFaction != factionAttacking->controllingFaction){
            int randBattle = rand() % 100;
            
            if (randBattle > 90)
            {
                factionDefending->controllingFaction=factionAttacking->controllingFaction;
                printf("battle! lost %d against %d!\n",factionDefending->controllingFaction, factionAttacking->controllingFaction  );
                
            }
        }
    }
}


void factionSpread()
{
    //spread through natural spawning
    factionSpawn();
    
    //spread through fighting
    for( auto q: buildingTileSet )
    {
        if (q->controllingFaction != tileConstants::NOT_CONTROLLED)
        {

                int toCheckX = q->tileItIs.Xtile;
                int toCheckY = q->tileItIs.Ytile+1;
                factionfight(toCheckX, toCheckY, q);
            
            

                toCheckX = q->tileItIs.Xtile;
                toCheckY = q->tileItIs.Ytile-1;
                factionfight(toCheckX, toCheckY, q);
            

                toCheckX = q->tileItIs.Xtile+1;
                toCheckY = q->tileItIs.Ytile;
                factionfight(toCheckX, toCheckY, q);
            
            

                toCheckX = q->tileItIs.Xtile-1;
                toCheckY = q->tileItIs.Ytile;
                factionfight(toCheckX, toCheckY, q);
            
            

        }
    }
}

void factionRequirments(int* scienceR, int* economicR, int* loreR, int* religionR, int* foodR){
    

    for( auto q: buildingTileSet )
    {
        if(q->controllingFaction == tileConstants::SCIENCE_CONTROLLED){
            *scienceR += q->pop;
        }
        if(q->controllingFaction == tileConstants::ECONOMIC_CONTROLLED){
            *economicR += q->pop;
        }
        if(q->controllingFaction == tileConstants::LORE_CONTROLLED){
            *loreR += q->pop;
        }
        if(q->controllingFaction == tileConstants::RELIGION_CONTROLLED){
            *religionR += q->pop;
        }
        *foodR += q->pop;
    }
}

