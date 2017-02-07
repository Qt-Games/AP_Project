//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_PLAYER_H
#define AP_PROJECT_PLAYER_H


#include "Object.h"
#include "GraphicScene.h"
#include "MyPlan.h"
#include "Bullet.h"

class Player : public QObject, public Object{

    Q_OBJECT

    int Score;
    int FuelPercentage;
    int lastmove;
    int speed;

    QImage* IMGraider;
    QImage* IMGraider_R;
    QImage* IMGraider_L;

    QTimer* timer;
public:
    static const int sizeX = 50;
    static const int sizeY = 50;

    Player(int posX, int posY, Direction direction);

    void setScore(int Score);
    void setFuelPercentage(int FuelPercentage);
    int getScore() const;
    int getFuelPercentage() const;
    void startTimer()
    {
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(10);
    }
    void rightKeyPressed();
    void leftKeyPressed();
    void spacekeyPressed();
    void otherKeyPressed();
    void leftKeyReleased();
    void rightKeyReleased();

public slots:
    void move();
};

#endif //AP_PROJECT_PLAYER_H
