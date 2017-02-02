//
// Created by Y50 on 2/2/2017.
//

#include "FuelDepot.h"
#include "GraphicScene.h"

FuelDepot::FuelDepot(int posX, int posY, Direction direction):
        DestructableObject(posX, posY, FuelDepot::speed, direction) {

    QGraphicsPixmapItem* fuelpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/fuel.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    fuelpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(fuelpxmap);

    fuelpxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(fuelpxmap);

}
