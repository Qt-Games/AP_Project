//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_DESTRUCTABLEOBJECT_H
#define AP_PROJECT_DESTRUCTABLEOBJECT_H


#include "ScrollingObject.h"

class DestructableObject : public ScrollingObject{


public:
    DestructableObject(int posX, int posY, int speed, Direction direction) : ScrollingObject(posX, posY, speed,
                                                                                             direction) { }

    void flip()
    {
        QImage image = this->getGraphicObject()->pixmap().toImage();
        getGraphicObject()->setPixmap(QPixmap::fromImage(image.mirrored(true, false)));
        setSpeed(-1 * getSpeed());
    }

    virtual bool canPassThroughMapObjects() = 0;

    void Destruct(){

    }
};


#endif //AP_PROJECT_DESTRUCTABLEOBJECT_H
