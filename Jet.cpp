//
// Created by dot_blue on 02/02/17.
//

#include "Jet.h"

bool Jet::canPassThroughMapObjects() {
    return true;
}

Jet::Jet(int posX, int posY, Direction direction) : EnemyObject(posX, posY, Jet::speed, direction) { }
