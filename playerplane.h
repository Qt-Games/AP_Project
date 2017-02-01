#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include <QtWidgets/QGraphicsRectItem>
#include <iostream>
#include <QKeyEvent>

class PlayerPlane : public QGraphicsPixmapItem
{
protected:

    virtual void keyPressEvent(QKeyEvent *event) override {
        if(event->key() == Qt::Key_Left)
        {
            setPos(x() - 10, y());
        }
        if(event->key() == Qt::Key_Right)
        {
            setPos(x() + 10, y());
        }
    }
};

#endif // PLAYERPLANE_H
