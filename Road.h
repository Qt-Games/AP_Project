//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_ROAD_H
#define AP_PROJECT_ROAD_H


#include "ScrollingObject.h"

class Road : ScrollingObject{

public:
    Road(int posX, int posY, int speed, Direction direction);
};


#endif //AP_PROJECT_ROAD_H
