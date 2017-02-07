//
// Created by dot_blue on 02/02/17.
//

#include <iostream>
#include "ScrollingObject.h"
#include "Model.h"


void ScrollingObject::scrollDown() {
    this->getGraphicObject()->moveBy(0, Model::ScrollAmount);
    this->setPosY(this->getPosY() + Model::ScrollAmount);
    //std::cout << getId() << std::endl;
}

void ScrollingObject::collide() {

}

ScrollingObject::ScrollingObject(int posX, int posY, int speed, Direction direction) :
        Object(posX, posY, speed, direction) {

}
