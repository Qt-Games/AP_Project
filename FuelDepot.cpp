//
// Created by Y50 on 2/2/2017.
//

#include "FuelDepot.h"
#include "GraphicScene.h"
#include "Player.h"

FuelDepot::FuelDepot(int posX, int posY, Direction direction):
        DestructableObject(posX, posY, FuelDepot::speed, direction) {

    isDestroyed=false;
    hasAddedFuelToPlayer = false;

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


void FuelDepot::hitByBullet() {
    isDestroyed=true;
    fuelpxmap->hide();
    std::cout<<"A FuelDepot has been destroyed!\n   What the hell are you doing?"<<std::endl;
    this->Destruct();
}

bool FuelDepot::hitByPlane() {
    if(!hasAddedFuelToPlayer)
    {
        std::cout<<"Plane has got some juice!"<<std::endl;
        int fuelPercentage = this->player->getFuelPercentage() + FuelDepot::AddedFuelPercentageOnCollision;
        if(fuelPercentage > 100)
        {
            fuelPercentage = 100;
        }
        this->player->setFuelPercentage(fuelPercentage);
    }
    hasAddedFuelToPlayer = true;
    return false;
}
