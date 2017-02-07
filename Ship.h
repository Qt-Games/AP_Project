//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_SHIP_H
#define AP_PROJECT_SHIP_H


#include "NonPassingThroughGrassObject.h"

class Ship : public NonPassingThroughGrassObject{

public:
    static const int sizeX = 100;
    static const int sizeY = 30;
    static const int speed = 2;

    Ship(int posX, int posY, Direction direction);

    virtual int getSizeX() override {
        return Ship::sizeX;
    }


};



#endif //AP_PROJECT_SHIP_H
