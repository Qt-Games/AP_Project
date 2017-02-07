//
// Created by dot_blue on 02/02/17.
//

#include "Jet.h"
#include "GraphicScene.h"

bool Jet::canPassThroughMapObjects() {
    return true;
}

Jet::Jet(int posX, int posY, Direction direction) : EnemyObject(posX, posY, Jet::speed, direction) {

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
