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

    Q_OBJECT

    QGraphicsPixmapItem* bulletpxmap;
public slots:
    void moveFront();

public:
    static const int sizeX = 40;
    static const int sizeY = 40;

    int pos_X,pos_Y;

    Bullet(int posX, int posY, int speed, Direction direction);
    ~Bullet();

    QTimer* timer;


};


#endif //AP_PROJECT_BULLET_H
