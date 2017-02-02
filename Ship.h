//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_SHIP_H
#define AP_PROJECT_SHIP_H


#include "NonPassingThroughGrassObject.h"

class Ship : public NonPassingThroughGrassObject{

public:
    Ship(int posX, int posY, int speed, Direction direction);
};



#endif //AP_PROJECT_SHIP_H
