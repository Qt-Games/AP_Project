//
// Created by Y50 on 2/2/2017.
//

#include "Helicopter.h"
#include "GraphicScene.h"

Helicopter::Helicopter(int posX, int posY, Direction direction) :
        NonPassingThroughGrassObject(posX, posY, Helicopter::speed, direction) {

    isDestroyed=false;

    this->destructionPoints = Helicopter::points;
    helicopterpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/heli.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    helicopterpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(helicopterpxmap);

    helicopterpxmap->setPos(posX,posY);

    if(direction == Direction::Left)
    {
        this->flip();
    }

    GraphicScene::getInstance()->addItem(helicopterpxmap);

}

bool Helicopter::isInTheObject(int Xpos, int Ypos) {
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

void Helicopter::hitByBullet() {
    isDestroyed=true;
    helicopterpxmap->hide();
    std::cout<<"A Helicopter has been destroyed!"<<std::endl;
    this->Destruct();
}

bool Helicopter::hitByPlane() {
    std::cout<<"Plane has been hit by a Helicopter!"<<std::endl;

    return true;
}


