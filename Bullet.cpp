//
// Created by dot_blue on 02/02/17.
//

#include "Bullet.h"
#include "GraphicScene.h"
#include <iostream>

using namespace std;

int Bullet::NumberOfBullets=0;
std::deque<MapStripe*> Bullet::level;
std::deque<MapStripe*> Bullet::tmpLevel;


Bullet::Bullet(int posX, int posY, int speed, Direction direction) : Object(posX, posY, speed, direction) {

    bulletpxmap=new QGraphicsPixmapItem();
    QString tmpstr(RES_PATH);
    tmpstr.append("/bullet.png");

    QImage image(tmpstr);
    image=image.scaled(sizeX,sizeY);

    bulletpxmap->setPixmap(QPixmap::fromImage(image));
    setGraphicObject(bulletpxmap);

    pos_X=posX;
    pos_Y=posY;
    bulletpxmap->setPos(posX,posY);

    GraphicScene::getInstance()->addItem(bulletpxmap);

    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveFront1()));

    timer->start(10);
    NumberOfBullets++;

}

void Bullet::moveFront1() {
    if(this->model->isPaused())
    {
        return;
    }
    if(bulletpxmap==NULL)
        return;

    pos_Y-=getSpeed();
    bulletpxmap->setPos(pos_X,pos_Y);

    if(pos_Y+30<0)
    {
        bulletpxmap=NULL;
        delete this;
    }

    check_collision();
//    for(){
//
//    }

}

void Bullet::check_collision() {
//    if(level){
//        return;
//    }

    for(std::deque<MapStripe*>::iterator it=tmpLevel.begin();it!=tmpLevel.end();it++){

        if((*it)->destructableObject!=NULL
           && (*it)->destructableObject->isInTheObject(pos_X+(Bullet::sizeX/2),pos_Y, Bullet::sizeX, Bullet::sizeY)
           && !((*it)->destructableObject->Destroyed())){
            (*it)->destructableObject->hitByBullet();
            (*it)->explodeDestructibleObject();

            delete (*it)->destructableObject;
            (*it)->destructableObject=NULL;

            if(NumberOfBullets!=0)
                delete this;
        }
        for (vector<ScrollingObject *>::iterator pit = (*it)->scrollingObjects.begin();
             pit != (*it)->scrollingObjects.end(); pit++) {
            if((*pit)->isInTheObject(pos_X+(Bullet::sizeX/2),pos_Y, Bullet::sizeX, Bullet::sizeY)){
                (*pit)->hitByBullet();
                if(NumberOfBullets!=0)
                    delete this;
            }
        }
    }

    for(std::deque<MapStripe*>::iterator it=level.begin();it!=level.end();it++){

        if((*it)->destructableObject!=NULL
           && (*it)->destructableObject->isInTheObject(pos_X+(Bullet::sizeX/2),pos_Y, Bullet::sizeX, Bullet::sizeY)
           && !((*it)->destructableObject->Destroyed())){
            (*it)->destructableObject->hitByBullet();
            (*it)->explodeDestructibleObject();

            delete (*it)->destructableObject;
            (*it)->destructableObject=NULL;

            if(NumberOfBullets!=0)
                delete this;
        }
        for (vector<ScrollingObject *>::iterator pit = (*it)->scrollingObjects.begin();
             pit != (*it)->scrollingObjects.end(); pit++) {
             if((*pit)->isInTheObject(pos_X+(Bullet::sizeX/2),pos_Y, Bullet::sizeX, Bullet::sizeY)){
                 (*pit)->hitByBullet();
                 if(NumberOfBullets!=0)
                    delete this;
             }
        }
    }
}

Bullet::~Bullet() {
    cout<<"Bullet is killed!!!"<<endl;
    NumberOfBullets--;

}

void Bullet::setModel(Model* model) {
    this->model = model;
}