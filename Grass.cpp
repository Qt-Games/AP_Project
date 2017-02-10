//
// Created by dot_blue on 02/02/17.
//

#include "Grass.h"
#include "GraphicScene.h"

Grass::Grass(int posX, int posY, int sizeX, int sizeY)
        :ScrollingObject(posX, posY, 0, Direction::Right), sizeX(sizeX), sizeY(sizeY) {

    GreenRec=new QGraphicsRectItem(posX,posY,sizeX,sizeY);
    GreenRec->setBrush(QBrush(QColor(0,255,0,255)));
    GreenRec->setPen(QPen(QColor(0,255,0,255)));
    GraphicScene::getInstance()->addItem(GreenRec);
}

bool Grass::isInTheObject(int Xpos, int Ypos) {

    if(posX<Xpos && Xpos<posX+sizeX)
    {
        if(posY<Ypos && Ypos<posY+sizeY)
        {
            return true;
        }
    }
    return false;
}

void Grass::hitByBullet() {
    std::cout<<"Grass is hitted by bullet"<<std::endl;
//    GreenRec->setBrush(QBrush(QColor(0,0,0,255)));
//    GreenRec->setPen(QPen(QColor(0,0,0,255)));
}

bool Grass::hitByPlane() {
    std::cout<<"Grass is collided by a plane"<<std::endl;
//    GreenRec->setBrush(QBrush(QColor(0,0,0,255)));
//    GreenRec->setPen(QPen(QColor(0,0,0,255)));
    return true;
}
