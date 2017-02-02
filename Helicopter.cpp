//
// Created by Y50 on 2/2/2017.
//

#include "Helicopter.h"
#include "GraphicScene.h"

Helicopter::Helicopter(int posX, int posY, Direction direction) :
        NonPassingThroughGrassObject(posX, posY, Helicopter::speed, direction) {

    QGraphicsPixmapItem* helicopterpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/heli.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    helicopterpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(helicopterpxmap);

    helicopterpxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(helicopterpxmap);

}


