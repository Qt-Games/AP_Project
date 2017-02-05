//
// Created by dot_blue on 05/02/17.
//

#ifndef AP_PROJECT_MYPLAN_H
#define AP_PROJECT_MYPLAN_H
#include <QGraphicsPixmapItem>

class MyPlan :public QGraphicsPixmapItem{

public:

    MyPlan(int speed);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    static const int sizeX = 50;
    static const int sizeY = 50;

    int lastmove;
    int speed;
    QImage* IMGraider;
    QImage* IMGraider_R;
    QImage* IMGraider_L;

};


#endif //AP_PROJECT_MYPLAN_H
