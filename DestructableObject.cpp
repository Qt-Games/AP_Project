//
// Created by Y50 on 2/2/2017.
//

#include "DestructableObject.h"
#include "Player.h"
void DestructableObject::Destruct() {
    player->setScore(player->getScore() + this->destructionPoints);
    std::cout<<"You have received "<<this->destructionPoints<<" points!"<<std::endl;
}

void DestructableObject::setPlayer(Player *player) {
    DestructableObject::player = player;
}

void DestructableObject::flip() {
    QImage image = this->getGraphicObject()->pixmap().toImage();
    getGraphicObject()->setPixmap(QPixmap::fromImage(image.mirrored(true, false)));
    setSpeed(-1 * getSpeed());
}

bool DestructableObject::Destroyed() {
    return isDestroyed;
}


