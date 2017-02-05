//
// Created by dot_blue on 02/02/17.
//

#include <iostream>
#include "Model.h"
#include "Map.h"
#include "Player.h"


Model::Model(){
    this->player = new Player(Model::SceneWidth, 0, Direction::Right);
    this->map = new Map();
}