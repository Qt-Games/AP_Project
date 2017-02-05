//
// Created by Y50 on 2/2/2017.
//

#include "Player.h"
#include "GraphicScene.h"

Player::Player(int posX, int posY, Direction direction) :
        Object(posX, posY, 0, direction) {

    this->FuelPercentage = 100;
    this->Score = 0;

    QGraphicsPixmapItem* playerpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/raider.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    playerpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(playerpxmap);

    playerpxmap->setPos(posX,posY);
    playerpxmap->setZValue(100);

    GraphicScene::getInstance()->addItem(playerpxmap);


}
