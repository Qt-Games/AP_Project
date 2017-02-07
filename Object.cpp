//
// Created by Y50 on 2/1/2017.
//

#include "Object.h"

int Object::id_generator = 0;

void Object::setDirection(Direction direction) {
    Object::direction = direction;
}

Direction Object::getDirection() const {
    return direction;
}

void Object::setSpeed(int speed) {
    Object::speed = speed;
}

int Object::getSpeed() const {
    return speed;
}

void Object::setPosY(int posY) {
    Object::posY = posY;
}

int Object::getPosY() const {
    return posY;
}

void Object::setPosX(int posX) {
    Object::posX = posX;
}

int Object::getPosX() const {
    return posX;
}

QGraphicsPixmapItem *Object::getGraphicObject() const {
    return GraphicObject;
}

void Object::setGraphicObject(QGraphicsPixmapItem *GraphicObject) {
    Object::GraphicObject = GraphicObject;
}

int Object::getId() const {
    return id;
}