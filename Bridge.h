//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_BRIDGE_H
#define AP_PROJECT_BRIDGE_H


#include "DestructableObject.h"

class Bridge : DestructableObject{

public:
    Bridge(int posX, int posY, int speed, Direction direction) :
            DestructableObject(posX, posY, speed, direction) { }

};


#endif //AP_PROJECT_BRIDGE_H
