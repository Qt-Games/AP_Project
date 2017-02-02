//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_JET_H
#define AP_PROJECT_JET_H

#include "EnemyObject.h"

class Jet : public EnemyObject{

public:
    static const int sizeX = 50;
    static const int sizeY = 30;
    static const int speed = 20;

    Jet(int posX, int posY, Direction direction);

private:
    virtual bool canPassThroughMapObjects();
};


#endif //AP_PROJECT_JET_H
