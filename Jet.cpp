//
// Created by dot_blue on 02/02/17.
//

#include "Jet.h"
#include "GraphicScene.h"

bool Jet::canPassThroughMapObjects() {
    return true;
}

Jet::Jet(int posX, int posY, Direction direction) : EnemyObject(posX, posY, Jet::speed, direction) {

    QGraphicsPixmapItem* jetpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/jet.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    jetpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(jetpxmap);

    jetpxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(jetpxmap);

}
