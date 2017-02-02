//
// Created by dot_blue on 02/02/17.
//

#include <cstdlib>
#include "Map.h"
#include "DestructableObject.h"
#include "FuelDepot.h"
#include "Model.h"

std::queue<MapStripe*> Map::createRandomLevel(int hardness) {
    std::queue<MapStripe*> result;

    for(int i = 0; i < 3; i++)
    {
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
            if(isThereFuelDepot)
            {
                int sizeX = FuelDepot::sizeX;
                int sceneX = Model::SceneWidth;



                destructableObject = new FuelDepot();
            }
            MapStripe* tempMapStripe = new MapStripe();

        }
    }
    return result;
}

void Map::addLevel(std::queue<MapStripe*> level) {

}

void Map::cleanPassedStripes() {

}

Map::Map() {
    addLevel(createRandomLevel());
}
