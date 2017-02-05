//
// Created by dot_blue on 02/02/17.
//

#include <iostream>
#include "Model.h"
#include "Map.h"
#include "Player.h"


Model::Model(){
    this->player = new Player(Model::SceneWidth / 2 - Player::sizeX / 2, (Model::SceneHeight - Player::sizeY) * 0.95-300 , Direction::Right);
    this->map = new Map();
}