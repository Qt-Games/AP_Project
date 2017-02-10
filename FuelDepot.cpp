//
// Created by Y50 on 2/2/2017.
//

#include "FuelDepot.h"
#include "GraphicScene.h"

FuelDepot::FuelDepot(int posX, int posY, Direction direction):
        DestructableObject(posX, posY, FuelDepot::speed, direction),isDestroyed(false) {

    this->destructionPoints = FuelDepot::points;

    fuelpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/fuel.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    fuelpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(fuelpxmap);

    fuelpxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(fuelpxmap);

}

bool FuelDepot::isInTheObject(int Xpos, int Ypos) {
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

void FuelDepot::hitByBullet() {
    isDestroyed=true;
    fuelpxmap->hide();
    std::cout<<"A FuelDepot has been destroyed!\n   What the hell are you doing?"<<std::endl;
    this->Destruct();
}

void FuelDepot::hitByPlane() {
    ScrollingObject::hitByPlane();
}
