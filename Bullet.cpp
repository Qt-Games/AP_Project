//
// Created by dot_blue on 02/02/17.
//

#include "Bullet.h"
#include "GraphicScene.h"

Bullet::Bullet(int posX, int posY, int speed, Direction direction) : Object(posX, posY, speed, direction) {

    QGraphicsPixmapItem* bulletpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/Bullet.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    bulletpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(bulletpxmap);

    bulletpxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(bulletpxmap);

}
