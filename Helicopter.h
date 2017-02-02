//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_HELLICOPTER_H
#define AP_PROJECT_HELLICOPTER_H


#include "NonPassingThroughGrassObject.h"

class Helicopter : public NonPassingThroughGrassObject{

public:
    Helicopter(int posX, int posY, int speed, Direction direction);
};


#endif //AP_PROJECT_HELLICOPTER_H
