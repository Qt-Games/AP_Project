//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_SCROLLINGOBJECT_H
#define AP_PROJECT_SCROLLINGOBJECT_H
#include "Object.h"

class ScrollingObject:public Object {

public:
    virtual void scrollDown();
    void collide();
    ScrollingObject(int posX, int posY, int speed, Direction direction);

};


#endif //AP_PROJECT_SCROLLINGOBJECT_H
