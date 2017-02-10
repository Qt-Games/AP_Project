//
// Created by Y50 on 2/10/2017.
//

#ifndef AP_PROJECT_EXPLOSION_H
#define AP_PROJECT_EXPLOSION_H


#include <QtGui/QImage>
#include <QTimer>
#include <QtWidgets/QGraphicsPixmapItem>
#include <iostream>
#include <QObject>
#include "ScrollingObject.h"

class MapStripe;

class Explosion : public ScrollingObject {
Q_OBJECT
    MapStripe* mapStripe;
    QImage *spritesheet;
    QTimer *timer;

    int sizeX;
    int sizeY;

    int currentFrame;
    bool Done;
public :
    static const int SpriteSize = 64;
    static const int SpritesInRow = 5;
    static const int SpritesInColumn = 5;

    Explosion(int posX, int posY, int sizeX, int sizeY, MapStripe* mapStripe);
    virtual int getSizeX();
    virtual int getSizeY();
    virtual ~Explosion();

    bool isDone();

public slots:

    void advanceTime();

};


#endif //AP_PROJECT_EXPLOSION_H
