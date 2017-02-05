//
// Created by Y50 on 2/2/2017.
//

#include "Player.h"

Player::Player(int posX, int posY, Direction direction) :
        Object(posX, posY, 0, direction) {

    this->FuelPercentage = 100;
    this->Score = 0;

    playerpxmap = new MyPlan(10);
    QString tmpstr(RES_PATH);
    tmpstr.append("/raider.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    playerpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(playerpxmap);

    playerpxmap->setPos(posX,posY);
    playerpxmap->setZValue(100);

    GraphicScene::getInstance()->addItem(playerpxmap);

    playerpxmap->setFlag(QGraphicsItem::ItemIsFocusable);
    playerpxmap->setFocus();

}


