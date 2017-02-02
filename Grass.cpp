//
// Created by dot_blue on 02/02/17.
//

#include "Grass.h"
#include "GraphicScene.h"

Grass::Grass(int posX, int posY, int sizeX, int sizeY) : ScrollingObject(posX, posY, 0, Direction::Right) {

    GreenRec=new QGraphicsRectItem(posX,posY,sizeX,sizeY);
    GreenRec->setBrush(QBrush(QColor(0,255,0,255)));
    GreenRec->setPen(QPen(QColor(0,255,0,255)));

    GraphicScene::getInstance()->addItem(GreenRec);


}
