//
// Created by dot_blue on 02/02/17.
//

#include <iostream>
#include "Model.h"
#include "Map.h"
#include "Player.h"
#include "mainwindow.h"
#include "Explosion.h"

void Model::start() {
    this->player = new Player(Model::SceneWidth / 2 - Player::sizeX / 2,
                              (Model::SceneHeight - Player::sizeY) * 0.95 -300  ,
                              Direction::Right);
    this->paused = false;
    map->startGame();
}

bool Model::isPaused() const {
    return paused;
}

void Model::setPaused(bool paused) {
    Model::paused = paused;
}


Model::Model(){
    this->player = NULL;
    this->paused = true;
    this->map = new Map(this);

}

void Model::setMainWindow(MainWindow *mainWindow) {
    Model::mainWindow = mainWindow;
}


void Model::advanceTime() {
    player->setFuelPercentage(player->getFuelPercentage() - Model::FuelDecreaseRate);
    mainWindow->updateView();
}

Player *Model::getPlayer() const {
    return player;
}

