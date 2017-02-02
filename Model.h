//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_MODEL_H
#define AP_PROJECT_MODEL_H


#include "Map.h"

class Player;

class Bullet;

class Model {
    Map* map;
    Player* player;
    Bullet* bullet;

public:
    Model(Map *map, Player *player, Bullet *bullet);
};


#endif //AP_PROJECT_MODEL_H
