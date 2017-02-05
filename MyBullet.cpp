//
// Created by dot_blue on 05/02/17.
//

#include <iostream>
#include "MyBullet.h"

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

}

MyBullet::~MyBullet() {

    delete timer;

}
