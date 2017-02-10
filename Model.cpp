//
// Created by dot_blue on 02/02/17.
//

#include <iostream>
#include "Model.h"
#include "Map.h"
#include "Player.h"
#include "mainwindow.h"
#include "Explosion.h"

int Model::ScrollAmount = Model::BaseScrollAmount;

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
    if(lastMove == 1)
    {
        if(Model::ScrollAmount < Model::MaxScrollAmount)
        {
            Model::ScrollAmount++;
        }
    }
    else if(lastMove == 0)
    {
        if(Model::ScrollAmount > Model::BaseScrollAmount)
        {
            Model::ScrollAmount --;
        }
        else if(Model::ScrollAmount < Model::BaseScrollAmount)
        {
            Model::ScrollAmount ++;
        }
    }
    else if(lastMove == -1)
    {
        if(Model::ScrollAmount > Model::MinScrollAmount)
        {
            Model::ScrollAmount--;
        }
    }

    std::cout << "current speed is : " <<  Model::ScrollAmount << std::endl;
    mainWindow->updateView();
}

Player *Model::getPlayer() const {
    return player;
}

void Model::upKeyPressed() {
    lastMove = 1;
}

void Model::downKeyPressed() {
    lastMove = -1;
}

void Model::upKeyReleased() {
    lastMove = 0;
}

void Model::downKeyReleased() {
    lastMove = 0;
}









