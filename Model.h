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
    static const int SceneWidth = 1000;
    static const int SceneHeight = 1000;
    static const int ScrollAmount = 10;
    Model(Map *map, Player *player);
};


#endif //AP_PROJECT_MODEL_H
