//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_BRIDGE_H
#define AP_PROJECT_BRIDGE_H


#include "DestructableObject.h"

class Bridge : public DestructableObject{
    int sizeX;
    int sizeY;
public:

    Bridge(int posX, int posY, int sizeX, int sizeY);

    virtual int getSizeX() override {
        return this->sizeX;
    }

    virtual bool canPassThroughMapObjects() override {
        return false;
    }
};


#endif //AP_PROJECT_BRIDGE_H
