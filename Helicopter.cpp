//
// Created by Y50 on 2/2/2017.
//

#include "Helicopter.h"

Helicopter::Helicopter(int posX, int posY, Direction direction) : NonPassingThroughGrassObject(posX, posY, Helicopter::speed,
                                                                                                            direction) { }


