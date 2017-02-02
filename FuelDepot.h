//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_FUELDEPOT_H
#define AP_PROJECT_FUELDEPOT_H


#include "DestructableObject.h"

class FuelDepot : public DestructableObject{

public:
    static const int sizeX = 50;
    static const int sizeY = 100;

    FuelDepot(int posX, int posY, int speed, Direction direction) :
            DestructableObject(posX, posY, speed, direction) { }
};


#endif //AP_PROJECT_FUELDEPOT_H
