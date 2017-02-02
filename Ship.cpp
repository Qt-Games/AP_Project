//
// Created by Y50 on 2/2/2017.
//

#include "Ship.h"

Ship::Ship(int posX, int posY, Direction direction) :
        NonPassingThroughGrassObject(posX, posY, Ship::speed, direction) { }
