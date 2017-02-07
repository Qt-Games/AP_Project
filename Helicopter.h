//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_HELLICOPTER_H
#define AP_PROJECT_HELLICOPTER_H


#include "NonPassingThroughGrassObject.h"

class Helicopter : public NonPassingThroughGrassObject{

public:
    static const int sizeX = 50;
    static const int sizeY = 30;
    static const int speed = 2;

    Helicopter(int posX, int posY, Direction direction);

    virtual int getSizeX() override {
        return Helicopter::sizeX;
    }
};


#endif //AP_PROJECT_HELLICOPTER_H
