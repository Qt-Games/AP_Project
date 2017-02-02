//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_NONPASSINGTHROUGHGRASSOBJECT_H
#define AP_PROJECT_NONPASSINGTHROUGHGRASSOBJECT_H

#include "EnemyObject.h"

class NonPassingThroughGrassObject : public EnemyObject{

public:
    NonPassingThroughGrassObject(int posX, int posY, int speed, Direction direction);
};

#endif //AP_PROJECT_NONPASSINGTHROUGHGRASSOBJECT_H
