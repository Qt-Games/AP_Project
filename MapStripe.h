//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_MAPSTRIPE_H
#define AP_PROJECT_MAPSTRIPE_H


#include "DestructableObject.h"
#include "Model.h"
#include "Explosion.h"
#include <thread>
#include <vector>
#include <QObject>
#include <QTimer>

using namespace std;

class MapStripe : public QObject {

    Q_OBJECT

    int posY;
    int sideBankWidth;
    int centerBankWidth;
    bool finished;
    QTimer* timer;
    vector<ScrollingObject*> scrollingObjects;
    Explosion* explosion;
    DestructableObject* destructableObject;
    Model* model;

public:
    static const int height = 120;
    MapStripe(Model* model,DestructableObject *destructableObject, int sideBankWidth, int centerBankWidth, int posY, bool isBridge);
    void addToScrollingObjects(ScrollingObject* scrollingObject);
    int getPosY() const;
    void setPosY(int posY);
    bool isFinished() const;
    void setFinished(bool isFinished);
    void explodeDestructibleObject();
    virtual ~MapStripe();


public slots:
    void advanceTime();

    friend class Bullet;
    friend class Player;

    void clearExplosion();
};


#endif //AP_PROJECT_MAPSTRIPE_H
