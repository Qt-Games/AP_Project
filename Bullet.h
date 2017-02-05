//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_BULLET_H
#define AP_PROJECT_BULLET_H
#include "Object.h"
#include "MyBullet.h"
#include <QTimer>
#include <QObject>


class Bullet: public Object {


    MyBullet* bulletpxmap;

public:
    static const int sizeX = 40;
    static const int sizeY = 40;

    Bullet(int posX, int posY, int speed, Direction direction);
    QTimer* timer;


};


#endif //AP_PROJECT_BULLET_H
