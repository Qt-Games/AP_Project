//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_SCROLLINGOBJECT_H
#define AP_PROJECT_SCROLLINGOBJECT_H
#include <Object.h>

class ScrollingObject:public Object {

public:
    ScrollingObject();

    ScrollingObject(int posX, int posY, int speed, Direction direction);

private:
    void ScrollDown();
    void Collide();

};


#endif //AP_PROJECT_SCROLLINGOBJECT_H
