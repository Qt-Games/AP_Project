//
// Created by Y50 on 2/1/2017.
//

#ifndef AP_PROJECT_OBJECT_H
#define AP_PROJECT_OBJECT_H

#include <QGraphicsPixmapItem>
#include "GraphicScene.h"
#include <QObject>


enum class Direction{
    Right, Left
};

class Object :public QObject{
    static int id_generator;

    int id;
    int posX;
    int posY;
    int speed;
    Direction direction;

    QGraphicsPixmapItem* GraphicObject;

public:

    Object(int posX, int posY, int speed, Direction direction) : posX(posX), posY(posY), speed(speed),
                                                                 direction(direction) {
        GraphicObject = NULL;
        id_generator ++;
        id = id_generator;
    }


    int getPosX() const;
    int getPosY() const;
    int getSpeed() const;
    Direction getDirection() const;
    QGraphicsPixmapItem *getGraphicObject() const;



    void setPosX(int posX);
    void setPosY(int posY);
    void setSpeed(int speed);
    void setDirection(Direction direction);
    void setGraphicObject(QGraphicsPixmapItem *GraphicObject);

    int getId() const;

    virtual ~Object() {
        QGraphicsPixmapItem* graphicsPixmapItem = this->getGraphicObject();
        if(graphicsPixmapItem != NULL)
        {
            GraphicScene::getInstance()->removeItem(graphicsPixmapItem);
            delete graphicsPixmapItem;
        }
    }
};



#endif //AP_PROJECT_OBJECT_H
