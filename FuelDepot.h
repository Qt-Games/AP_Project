//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_FUELDEPOT_H
#define AP_PROJECT_FUELDEPOT_H


#include "DestructableObject.h"

class FuelDepot : public DestructableObject{

    QGraphicsPixmapItem* fuelpxmap;


public:
    static const int sizeX = 50;
    static const int sizeY = 100;
    static const int speed = 0;
    static const int points = 150;

    bool hasAddedFuelToPlayer;

    FuelDepot(int posX, int posY, Direction direction);

    virtual int getSizeX() override {
        return FuelDepot::sizeX;
    }
    virtual int getSizeY() override {
        return FuelDepot::sizeY;
    }

    virtual bool canPassThroughMapObjects() override {
        return false;
    }


    virtual void hitByBullet() override;

    virtual bool hitByPlane() override;

};


#endif //AP_PROJECT_FUELDEPOT_H
