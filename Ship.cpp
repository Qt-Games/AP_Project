//
// Created by Y50 on 2/2/2017.
//

#include "Ship.h"
#include "GraphicScene.h"

Ship::Ship(int posX, int posY, Direction direction) :
        NonPassingThroughGrassObject(posX, posY, Ship::speed, direction) {

    isDestroyed=false;

    this->destructionPoints = Ship::points;
    shippxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/Ship.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    shippxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(shippxmap);

    shippxmap->setPos(posX,posY);

    if(direction == Direction::Left)
    {
        this->flip();
    }

    GraphicScene::getInstance()->addItem(shippxmap);

}

void Ship::hitByBullet() {
    isDestroyed=true;
    shippxmap->hide();
    std::cout<<"A Ship has been destroyed!"<<std::endl;
    this->Destruct();
}

bool Ship::hitByPlane() {
    std::cout<<"Plane has been hit by a Ship!"<<std::endl;

    return true;
}
