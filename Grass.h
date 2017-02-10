//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_GRASS_H
#define AP_PROJECT_GRASS_H

#include "ScrollingObject.h"
#include "Model.h"
#include <QBrush>
#include <QPen>

class Grass: public ScrollingObject {
    int sizeX;
    int sizeY;
public:
    Grass(int posX, int posY, int sizeX, int sizeY);

    virtual ~Grass();

private:
    QGraphicsRectItem* GreenRec;
public:
    virtual void scrollDown() override;

    virtual int getSizeX() override {
        return sizeX;
    }

    virtual int getSizeY() override {
        return sizeY;
    }

    virtual void hitByBullet() override;

    virtual bool hitByPlane() override;

};


#endif //AP_PROJECT_GRASS_H
