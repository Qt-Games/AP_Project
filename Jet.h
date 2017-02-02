//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_JET_H
#define AP_PROJECT_JET_H

#include "EnemyObject.h"

class Jet {
public:
    Jet(int posX, int posY, int speed, Direction direction);
    virtual canPassThroughMapObjects(int posX, int posY, int speed, Direction direction);



};


#endif //AP_PROJECT_JET_H
