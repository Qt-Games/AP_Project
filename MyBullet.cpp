//
// Created by dot_blue on 05/02/17.
//

#include <iostream>
#include "MyBullet.h"
#include "MyPlan.h"
#include "Helicopter.h"
#include "DestructableObject.h"
#include <QList>
#include <typeinfo>

MyBullet::MyBullet() {
    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(moveFront()));

    timer->start(40);



}

void MyBullet::moveFront() {

    moveBy(0,-20);
    if(y()+30<0)
    {
        delete this;
    }
    QList<QGraphicsItem *> collidingItems=this->collidingItems();
    for(auto it=collidingItems.begin();it!=collidingItems.end();it++){
        if(typeid(**it)!=typeid(MyPlan )) {
            (*it)->hide();
            delete this;
            std::cout << "bullet has been hit to the target" << std::endl;
        }
        else
        {
            std::cout << "heheh" << std::endl;
        }

    }

}

MyBullet::~MyBullet() {

    delete timer;

}
