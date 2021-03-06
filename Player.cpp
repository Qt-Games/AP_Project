//
// Created by Y50 on 2/2/2017.
//

#include <iostream>
#include "Player.h"
#include "Explosion.h"

std::deque<MapStripe*> Player::level;
std::deque<MapStripe*> Player::tmpLevel;

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
    bullet=NULL;
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
    if(Bullet::NumberOfBullets<1)
    {
        bullet=new Bullet((int)getGraphicObject()->x(),(int)getGraphicObject()->y(),20,Direction::Right);
        bullet->setModel(model);
    }
}

void Player::leftKeyPressed() {
    lastmove = -1;
}

void Player::rightKeyPressed() {
    lastmove = 1;
}


void Player::move() {
    if(this->model->isPaused())
    {
        return;
    }
    if(lastmove == 1)
    {
        speed += 1;
    }
    if(lastmove == -1)
    {
        speed -= 1;
    }
    if(lastmove == 0)
    {
        speed = 0;
    }
    getGraphicObject()->moveBy(speed / 10,0);
    posX+=speed / 10;
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
    check_collision();
}

void Player::check_collision() {
    for(std::deque<MapStripe*>::iterator it=tmpLevel.begin();it!=tmpLevel.end();it++){

        if((*it)->destructableObject!=NULL
            && (*it)->destructableObject->isInTheObject(posX+(Player::sizeX/2),posY, Player::sizeX*0.8, Player::sizeY*0.8)
               && !((*it)->destructableObject->Destroyed())){
            if((*it)->destructableObject->hitByPlane()){
                this->destroy();
                return;
            }

        }
        for (vector<ScrollingObject *>::iterator pit = (*it)->scrollingObjects.begin();
             pit != (*it)->scrollingObjects.end(); pit++) {
            if((*pit)->isInTheObject(posX+(Player::sizeX/2),posY, Player::sizeX*0.8, Player::sizeY*0.8) && !((*pit)->Destroyed())){
                if((*pit)->hitByPlane()){
                    this->destroy();
                    return;
                }
            }
        }
    }

    for(std::deque<MapStripe*>::iterator it=level.begin();it!=level.end();it++){

        if((*it)->destructableObject!=NULL
           && (*it)->destructableObject->isInTheObject(posX+(Player::sizeX/2),posY, Player::sizeX*0.8, Player::sizeY*0.8)
              && !((*it)->destructableObject->Destroyed())){
            if((*it)->destructableObject->hitByPlane()){
                this->destroy();
                return;
            }

        }
        for (vector<ScrollingObject *>::iterator pit = (*it)->scrollingObjects.begin();
             pit != (*it)->scrollingObjects.end(); pit++) {
            if((*pit)->isInTheObject(posX+(Player::sizeX/2),posY, Player::sizeX*0.8,Player::sizeY*0.8) && !((*pit)->Destroyed())){
                if((*pit)->hitByPlane()){
                    this->destroy();
                    return;
                }
            }
        }
    }
}

void Player::destroy() {

    //getGraphicObject()->hide();
    //Explosion tmp_Exp(posX, posY , 100 , 100, NULL);

    cout<<"Plane has been destroyed"<<endl;
    timer->stop();
    this->model->gameOver("You hit an obstacle!");

    //while(!tmp_Exp.isDone()){}
}

Bullet *Player::getBullet() const {
    return bullet;
}


void Player::startTimer() {
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void Player::setModel(Model* model) {
    this->model = model;
}

Player::~Player() {
    delete timer;
}
