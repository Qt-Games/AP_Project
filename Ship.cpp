//
// Created by Y50 on 2/2/2017.
//

#include "Ship.h"
#include "GraphicScene.h"

Ship::Ship(int posX, int posY, Direction direction) :
        NonPassingThroughGrassObject(posX, posY, Ship::speed, direction) {

    QGraphicsPixmapItem* shippxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/Ship.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    shippxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(shippxmap);

    shippxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(shippxmap);

}
