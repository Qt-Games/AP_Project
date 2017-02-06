//
// Created by dot_blue on 02/02/17.
//

#include <iostream>
#include "Model.h"
#include "Map.h"
#include "Player.h"


void Model::start() {
    this->map->startTimer();
}

bool Model::isPaused() const {
    return paused;
}

void Model::setPaused(bool paused) {
    Model::paused = paused;
}


Model::Model(){

    this->paused = true;

    this->player = new Player(Model::SceneWidth / 2 - Player::sizeX / 2,
                              (Model::SceneHeight - Player::sizeY) * 0.95 -300  ,
                              Direction::Right);

    this->map = new Map(this);
}