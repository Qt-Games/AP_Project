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
    static const int speed = 10;
    static const int points = 100;

    Jet(int posX, int posY, Direction direction);

    virtual ~Jet(){}

private:
    virtual bool canPassThroughMapObjects();

    QGraphicsPixmapItem* jetpxmap;


public:

    virtual void hitByBullet() override;

    virtual bool hitByPlane() override;

public:
    virtual int getSizeX() override {
        return Jet::sizeX;
    }
    virtual int getSizeY() override {
        return Jet::sizeY;
    }


};


#endif //AP_PROJECT_JET_H
