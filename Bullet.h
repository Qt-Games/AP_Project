//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_BULLET_H
#define AP_PROJECT_BULLET_H
#include "Object.h"
#include "MapStripe.h"
#include <QTimer>
#include <QObject>
#include <queue>
#include <deque>


class Bullet: public Object {

    Q_OBJECT

    QGraphicsPixmapItem* bulletpxmap;
public slots:
    void moveFront1();

public:
    static const int sizeX = 40;
    static const int sizeY = 40;
    static int NumberOfBullets;
    static std::deque<MapStripe*> level;
    static std::deque<MapStripe*> tmpLevel;


    Bullet(int posX, int posY, int speed, Direction direction);
    ~Bullet();

    void check_collision();


private:
    int pos_X,pos_Y;

    QTimer* timer;

};


#endif //AP_PROJECT_BULLET_H
