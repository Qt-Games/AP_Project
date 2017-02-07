//
// Created by Y50 on 2/2/2017.
//

#include <iostream>
#include "Player.h"

Player::Player(int posX, int posY, Direction direction) :
        Object(posX, posY, 0, direction) {

    this->FuelPercentage = 100;
    this->Score = 0;
    this->speed = 0;
    this->lastmove = 0;

    QString raider(RES_PATH);
    raider.append("/raider.png");
    QImage IMGtmp(raider);
    IMGraider=new QImage(IMGtmp.scaled(sizeX,sizeY));

    QString raider_R(RES_PATH);
    raider_R.append("/raider_mv_right.png");
    QImage IMGtmp1(raider_R);
    IMGraider_R=new QImage(IMGtmp1.scaled(sizeX-10,sizeY));

    QString raider_L(RES_PATH);
    raider_L.append("/raider_mv_left.png");
    QImage IMGtmp2(raider_L);
    IMGraider_L=new QImage(IMGtmp2.scaled(sizeX-10,sizeY));

//    playerpxmap = new MyPlan(10);
    QString tmpstr(RES_PATH);
    tmpstr.append("/raider.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    this->setGraphicObject(new QGraphicsPixmapItem());
    getGraphicObject()->setPixmap(QPixmap::fromImage(image));

    getGraphicObject()->setPos(posX,posY);
    getGraphicObject()->setZValue(100);

    GraphicScene::getInstance()->addItem(getGraphicObject());

    startTimer();
//    playerpxmap->setFlag(QGraphicsItem::ItemIsFocusable);
//    playerpxmap->setFocus();
}


void Player::setFuelPercentage(int FuelPercentage) {
    Player::FuelPercentage = FuelPercentage;
}

void Player::setScore(int Score) {
    Player::Score = Score;
}

int Player::getFuelPercentage() const {
    return FuelPercentage;
}

int Player::getScore() const {
    return Score;
}

void Player::rightKeyReleased() {
    getGraphicObject()->setPixmap(QPixmap::fromImage(*IMGraider));
    lastmove=0;
}

void Player::leftKeyReleased() {
    getGraphicObject()->setPixmap(QPixmap::fromImage(*IMGraider));
    lastmove=0;
}

void Player::otherKeyPressed() {
    getGraphicObject()->setPixmap(QPixmap::fromImage(*IMGraider));
    speed = 0;
    lastmove = 0;
}

void Player::spacekeyPressed() {
    Bullet* bullet=new Bullet((int)getGraphicObject()->x(),(int)getGraphicObject()->y(),10,Direction::Right);
}

void Player::leftKeyPressed() {
    lastmove = -1;
}

void Player::rightKeyPressed() {
    lastmove = 1;
}


void Player::move() {
    if(lastmove == 1)
    {
        speed += 2;
    }
    if(lastmove == -1)
    {
        speed -= 2;
    }
    if(lastmove == 0)
    {
        speed = 0;
    }
    getGraphicObject()->moveBy(speed / 10,0);
    if(speed < 0) {
        getGraphicObject()->setPixmap(QPixmap::fromImage(*IMGraider_L));
    }
    else if(speed > 0)
    {
        getGraphicObject()->setPixmap(QPixmap::fromImage(*IMGraider_R));
    }
    else{
        getGraphicObject()->setPixmap(QPixmap::fromImage(*IMGraider));
    }
}
