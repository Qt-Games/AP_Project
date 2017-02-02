//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_GRASS_H
#define AP_PROJECT_GRASS_H

#include "ScrollingObject.h"
#include <QBrush>
#include <QPen>

class Grass: public ScrollingObject {
public:

    Grass(int posX, int posY, int sizeX, int sizeY, Direction direction);
private:
    QGraphicsRectItem* GreenRec;

};


#endif //AP_PROJECT_GRASS_H
