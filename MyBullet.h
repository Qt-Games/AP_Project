//
// Created by dot_blue on 05/02/17.
//

#ifndef AP_PROJECT_MYBULLET_H
#define AP_PROJECT_MYBULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class MyBullet:public QObject,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    MyBullet();
    ~MyBullet();
public slots:
    void moveFront();
private:
    QTimer * timer;


};


#endif //AP_PROJECT_MYBULLET_H
