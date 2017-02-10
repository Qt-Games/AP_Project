//
// Created by Y50 on 2/2/2017.
//

#include <iostream>
#include "Road.h"
#include "GraphicScene.h"

Road::Road(int posX, int posY, int sizeX, int sizeY) :
        ScrollingObject(posX, posY, 0, Direction::Right), sizeX(sizeX), sizeY(sizeY) {

    QGraphicsPixmapItem* roadpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/road.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    roadpxmap->setPixmap(QPixmap::fromImage(image));
    roadpxmap->setPos(posX,posY);

    std::cout << "a road is created : " << roadpxmap->pos().x() << std::endl;
    setGraphicObject(roadpxmap);
    GraphicScene::getInstance()->addItem(roadpxmap);



}


void Road::hitByBullet() {
    std::cout<<"Road is hitted by bullet"<<std::endl;
}

bool Road::hitByPlane() {
    std::cout<<"Plane has been hit by a Road!"<<std::endl;

    return true;
}
