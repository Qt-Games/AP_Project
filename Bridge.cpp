//
// Created by Y50 on 2/2/2017.
//

#include "Bridge.h"
#include "GraphicScene.h"

Bridge::Bridge(int posX, int posY, int sizeX, int sizeY) :
        DestructableObject(posX, posY, 0, Direction::Right), sizeX(sizeX), sizeY(sizeY),isDestroyed(false) {

    this->destructionPoints = Bridge::points;

    bridgepxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/bridge.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    bridgepxmap->setPixmap(QPixmap::fromImage(image));
    bridgepxmap->setPos(posX,posY);

    setGraphicObject(bridgepxmap);
    GraphicScene::getInstance()->addItem(bridgepxmap);

}

bool Bridge::isInTheObject(int Xpos, int Ypos) {
    if(isDestroyed)
        return false;
    if(posX<Xpos && Xpos<posX+sizeX)
    {
        if(posY<Ypos && Ypos<posY+sizeY)
        {
            return true;
        }
    }
    return false;
}

void Bridge::hitByBullet() {

    isDestroyed=true;
    bridgepxmap->hide();
    std::cout<<"Bridge destroyed!"<<std::endl;

}

