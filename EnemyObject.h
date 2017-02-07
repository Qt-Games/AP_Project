//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_ENEMYOBJECT_H
#define AP_PROJECT_ENEMYOBJECT_H

#include "DestructableObject.h"

class EnemyObject:public DestructableObject {
public:
    EnemyObject(int posX, int posY, int speed, Direction direction);
};


#endif //AP_PROJECT_ENEMYOBJECT_H
