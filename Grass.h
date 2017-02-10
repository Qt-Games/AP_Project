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
private:
    QGraphicsRectItem* GreenRec;
public:
    virtual void scrollDown() override {
        this->GreenRec->moveBy(0, Model::ScrollAmount);
        this->setPosY(this->getPosY() + Model::ScrollAmount);
        //posY+=Model::ScrollAmount;
        //std::cout << getId() << std::endl;
    }

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
