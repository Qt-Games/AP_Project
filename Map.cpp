//
// Created by dot_blue on 02/02/17.
//

#include <cstdlib>
#include <iostream>
#include "Map.h"
#include "DestructableObject.h"
#include "FuelDepot.h"
#include "Model.h"
#include "MapStripe.h"
#include "Helicopter.h"
#include "Ship.h"
#include "Jet.h"

std::queue<MapStripe*> Map::createRandomLevel(int hardness) {
    std::queue<MapStripe*> result;

    for(int i = 0; i < 3; i++)
    {
        cout << " STAGE " << i << endl << endl;
        int length = 10 + rand() % 5;
        int sideBank = 10 * (rand() % 20);
        bool isThereCenterBank = (rand() % 5 == 0);
        int centerBank = 0;
        if(isThereCenterBank)
        {
            centerBank = 10 * (rand()  % 10);
        }
        for (int j = 0; j < length; ++j) {

            bool isThereFuelDepot = (rand() % (hardness + 2) == 0);
            bool isThereEnemyObject = (rand() % 10 < hardness);
            DestructableObject* destructableObject = NULL;
            int enemyTypeRandom = 0;
            int sizeX = 0;

            if(isThereFuelDepot)
            {
                sizeX = FuelDepot::sizeX;
            }
            else{
                if(isThereEnemyObject)
                {
                    enemyTypeRandom = rand() % 3;
                    switch(enemyTypeRandom)
                    {
                        case 0:
                            sizeX = Helicopter::sizeX;
                            break;
                        case 1:
                            sizeX = Ship::sizeX;
                            break;
                        case 2:
                            sizeX = Jet::sizeX;
                            break;
                        default:
                            std::cout << "UnExpected Error Happened";
                            exit(0);
                    }
                }
            }

            Direction direction;
            int directionRandom = rand() % 2;
            if(directionRandom == 1)    direction = Direction::Left;
            else                        direction = Direction::Right;



            int sceneX = Model::SceneWidth;
            int xRandomMin;
            int xRandomMax;
            int x;

            if(isThereCenterBank)
            {
                xRandomMin = sideBank;
                xRandomMax = sceneX - sizeX - sideBank;
            }
            else
            {
                int whichSideRandom = rand() % 2;
                if(whichSideRandom == 0)
                {
                    xRandomMin = sizeX;
                    xRandomMax = (sceneX/2) - centerBank - sizeX;
                }
                else
                {
                    xRandomMin = (sceneX/2) + centerBank;
                    xRandomMax = sceneX - sideBank - sizeX;
                }
            }
            x = xRandomMin + rand() % (xRandomMax - xRandomMin);


            if(isThereFuelDepot)
            {
                destructableObject = new FuelDepot(x, 0, direction);
            }
            else
            {
                if(isThereEnemyObject)
                {
                    switch(enemyTypeRandom)
                    {
                        case 0:
                            cout << "Helicopter" << endl;
                            destructableObject = new Helicopter(x, 0, direction);
                            break;
                        case 1:
                            cout << "Ship" << endl;
                            destructableObject = new Ship(x, 0, direction);
                            break;
                        case 2:
                            cout << "Jet" << endl;
                            destructableObject = new Jet(x, 0, direction);
                            break;
                        default:
                            break;
                    }
                }
            }
            cout << "side bank : " << sideBank << endl;
            cout << "center bank : " << centerBank << endl;
            cout << "sizeX : " << sizeX << endl;
            cout << xRandomMin << "   to    " << xRandomMax << endl;
            cout << "destructable x : " << x << endl;
            cout << endl << endl;

            MapStripe* tempMapStripe = new MapStripe(destructableObject, sideBank, centerBank);
        }
    }
    return result;
}

void Map::addLevel(std::queue<MapStripe*> level) {

}

void Map::cleanPassedStripes() {

}

Map::Map() {
    addLevel(createRandomLevel(1));
}
