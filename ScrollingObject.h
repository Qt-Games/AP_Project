//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_SCROLLINGOBJECT_H
#define AP_PROJECT_SCROLLINGOBJECT_H
#include "Object.h"
#include "Model.h"
#include <iostream>

class ScrollingObject:public Object {

public:
    virtual bool isInTheObject(int Xpos,int Ypos){
        return false;
    };
    virtual bool Destroyed();

    virtual void scrollDown();
    void collide();
    ScrollingObject(int posX, int posY, int speed, Direction direction);

    virtual int getSizeX() = 0;
    virtual int getSizeY() = 0;

    void move()
    {
        getGraphicObject()->moveBy(getSpeed() , 0);
        this->setPosX(this->getPosX() + getSpeed());

        if(this->getPosX() < (-1 * getSizeX()))
        {
            this->setPosX(Model::SceneWidth);
            this->getGraphicObject()->setPos(Model::SceneWidth, this->getGraphicObject()->y());
        }
        if(this->getPosX() > Model::SceneWidth)
        {
            this->setPosX(-1 * getSizeX());
            this->getGraphicObject()->setPos(-1 * getSizeX(), this->getGraphicObject()->y());
        }
    }

    virtual void hitByBullet(){};
    virtual bool hitByPlane(){};//return true if the plane is supposed to be destroyed
};


#endif //AP_PROJECT_SCROLLINGOBJECT_H
