//
// Created by Y50 on 2/2/2017.
//

#include "Bridge.h"

Bridge::Bridge(int posX, int posY) : DestructableObject(posX, posY, 0, Direction::Right) {

    QGraphicsPixmapItem* bridgepxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/bridge.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    bridgepxmap->setPixmap(QPixmap::fromImage(image));

    setGraphicObject(bridgepxmap);

}

