//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_MAP_H
#define AP_PROJECT_MAP_H

#include <queue>
#include "MapStripe.h"

class MapStripe;

class Map {
public:

    std::queue<MapStripe*> createRandomLevel(int hardness);
    void addLevel(std::queue<MapStripe*> level);
    void cleanPassedStripes();

    Map();

    std::queue<MapStripe*> mapStripes;
private:

};


#endif //AP_PROJECT_MAP_H
