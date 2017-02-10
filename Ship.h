//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_SHIP_H
#define AP_PROJECT_SHIP_H


#include "NonPassingThroughGrassObject.h"

class Ship : public NonPassingThroughGrassObject{

    QGraphicsPixmapItem* shippxmap;



public:
    static const int sizeX = 100;
    static const int sizeY = 30;
    static const int speed = 2;
    static const int points = 30;

    Ship(int posX, int posY, Direction direction);

    virtual ~Ship() {
    }

    virtual int getSizeX() override {
        return Ship::sizeX;
    }
    virtual int getSizeY() override {
        return Ship::sizeY;
    }

    virtual void hitByBullet() override;

    virtual bool hitByPlane() override;

};



#endif //AP_PROJECT_SHIP_H
