//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_GRASS_H
#define AP_PROJECT_GRASS_H

#include "ScrollingObject.h"

class Grass: public ScrollingObject {
public:
    Grass(int posX, int posY, int speed, Direction direction);
};


#endif //AP_PROJECT_GRASS_H
