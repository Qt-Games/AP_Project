//
// Created by dot_blue on 02/02/17.
//

#include "Jet.h"
#include "GraphicScene.h"

bool Jet::canPassThroughMapObjects() {
    return true;
}

Jet::Jet(int posX, int posY, Direction direction) : EnemyObject(posX, posY, Jet::speed, direction) {

    isDestroyed=false;

    this->destructionPoints = Jet::points;
    jetpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/jet.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    jetpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(jetpxmap);

    jetpxmap->setPos(posX,posY);

    if(direction == Direction::Left)
    {
        this->flip();
    }

    GraphicScene::getInstance()->addItem(jetpxmap);
    getGraphicObject()->setZValue(50);

}

bool Jet::isInTheObject(int Xpos, int Ypos) {
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

void Jet::hitByBullet() {
    isDestroyed=true;
    jetpxmap->hide();
    std::cout<<"A Jet has been destroyed!"<<std::endl;
    this->Destruct();
}

bool Jet::hitByPlane() {
    std::cout<<"Plane has been hit by a Jet!"<<std::endl;

    return true;
}
