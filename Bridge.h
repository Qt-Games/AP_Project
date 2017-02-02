//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_BRIDGE_H
#define AP_PROJECT_BRIDGE_H


#include "DestructableObject.h"

class Bridge : public DestructableObject{

public:
    static const int sizeX = 50;
    static const int sizeY = 30;

    Bridge(int posX, int posY);

};


#endif //AP_PROJECT_BRIDGE_H
