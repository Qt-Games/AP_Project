//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_PLAYER_H
#define AP_PROJECT_PLAYER_H


#include "Object.h"
#include "GraphicScene.h"
#include "MyPlan.h"

class Player : public Object{
    int Score;
    int FuelPercentage;
    MyPlan* playerpxmap;

public:
    static const int sizeX = 50;
    static const int sizeY = 50;
    static const int speed = 0;

    Player(int posX, int posY, Direction direction);

};



#endif //AP_PROJECT_PLAYER_H
