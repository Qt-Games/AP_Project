//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_HOUSE_H
#define AP_PROJECT_HOUSE_H

#include "ScrollingObject.h"

class House:public ScrollingObject{
public:
    static const int sizeX = 50;
    static const int sizeY = 50;
    House(int posX, int posY, int speed, Direction direction);

    virtual int getSizeX() override {
        return House::sizeX;
    }

    virtual int getSizeY() override {
        return House::sizeY;
    }

};



#endif //AP_PROJECT_HOUSE_H
