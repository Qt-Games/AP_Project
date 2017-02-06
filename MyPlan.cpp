//
// Created by dot_blue on 05/02/17.
//

#include "MyPlan.h"
#include "Bullet.h"
#include <iostream>
#include <QKeyEvent>

MyPlan::MyPlan(int speed):speed(speed){
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
}

void MyPlan::keyPressEvent(QKeyEvent *event) {

    if(event->key()==Qt::Key_Left){
        if(lastmove!=1)
            speed=10;
        moveBy(-speed,0);
        setPixmap(QPixmap::fromImage(*IMGraider_L));
        if(speed<=30)
            speed+=2;
    }
    else if(event->key()==Qt::Key_Right){
        if(lastmove!=-1)
            speed=10;
        moveBy(speed,0);
        setPixmap(QPixmap::fromImage(*IMGraider_R));
        speed++;
        if(speed<=30)
            speed+=2;
    }
    else if(event->key()==Qt::Key_Space)
    {
        Bullet* bullet=new Bullet(x(),y(),10,Direction::Right);
    }
    else
    {
        setPixmap(QPixmap::fromImage(*IMGraider));
    }

}

void MyPlan::keyReleaseEvent(QKeyEvent *event) {

    //speed=10;
    if(event->key()==Qt::Key_Left){
        setPixmap(QPixmap::fromImage(*IMGraider));
        lastmove=1;
        //speed=10;
    }
    else if(event->key()==Qt::Key_Right){
        setPixmap(QPixmap::fromImage(*IMGraider));
        lastmove=-1;
        //speed=10;
    }
}
