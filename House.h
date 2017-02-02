//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_HOUSE_H
#define AP_PROJECT_HOUSE_H

#include "ScrollingObject.h"

class House:public ScrollingObject{
public:


    House(int posX, int posY, int speed, Direction direction);
};



#endif //AP_PROJECT_HOUSE_H
