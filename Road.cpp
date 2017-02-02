//
// Created by Y50 on 2/2/2017.
//

#include "Road.h"
#include "GraphicScene.h"

Road::Road(int posX, int posY, int sizeX, int sizeY) : ScrollingObject(posX, posY, 0, Direction::Right) {

    QGraphicsPixmapItem* roadpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/road.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    roadpxmap->setPixmap(QPixmap::fromImage(image));
    roadpxmap->setPos(posX,posY);

    setGraphicObject(roadpxmap);
    GraphicScene::getInstance()->addItem(roadpxmap);

}
