//
// Created by Y50 on 2/2/2017.
//

#include "MapStripe.h"
#include "Grass.h"
#include "Model.h"
#include <cstdlib>
#include "Road.h"
#include <iostream>
#include <QTimer>


MapStripe::MapStripe(DestructableObject *destructableObject, int sideBankWidth, int centerBankWidth, int posY, bool isBridge)
        : destructableObject(destructableObject), sideBankWidth(sideBankWidth), centerBankWidth(centerBankWidth) {

    finished = false;
    this->posY = posY;

    if(isBridge)
    {
        Road* leftSideRoad = new Road(0, posY, sideBankWidth, MapStripe::height);
        addToScrollingObjects(leftSideRoad);
        Road* rightSideRoad = new Road(Model::SceneWidth - sideBankWidth, posY, sideBankWidth, MapStripe::height);
        addToScrollingObjects(rightSideRoad);
    }
    else
    {
        Grass* leftSideGrass = new Grass(0, posY, sideBankWidth, MapStripe::height);
        std::cout << "left side grass from 0 to " << sideBankWidth << endl;
        addToScrollingObjects(leftSideGrass);

        if(centerBankWidth != 0) {
            Grass *CenterGrass = new Grass((Model::SceneWidth / 2) - centerBankWidth, posY, centerBankWidth * 2,MapStripe::height);
            std::cout << "center grass from " << (Model::SceneWidth / 2) - centerBankWidth << " to " <<  (Model::SceneWidth / 2) - centerBankWidth + centerBankWidth*2 << endl;
            addToScrollingObjects(CenterGrass);
        }
        Grass* rightSideGrass = new Grass(Model::SceneWidth - sideBankWidth, posY, sideBankWidth, MapStripe::height);
        std::cout << "right side grass from " << Model::SceneWidth - sideBankWidth << " to " << Model::SceneWidth << endl;
        addToScrollingObjects(rightSideGrass);

        std::cout << std::endl << std::endl;
    }

    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(scrollDown()));

    timer->start(10);
}


MapStripe::~MapStripe() {

    cout << "one stripe is cleaned " << endl;
    delete timer;
    for(ScrollingObject* scrollingObject: scrollingObjects)
    {
        delete scrollingObject;
    }
    delete destructableObject;
}


void MapStripe::addToScrollingObjects(ScrollingObject *scrollingObject) {
    scrollingObjects.push_back(scrollingObject);
}

void MapStripe::setPosY(int posY) {
    MapStripe::posY = posY;
}

int MapStripe::getPosY() const {
    return posY;
}

void MapStripe::setFinished(bool isFinished) {
    MapStripe::finished = isFinished;
}

bool MapStripe::isFinished() const {
    return finished;
}

void MapStripe::scrollDown() {
    for(ScrollingObject* scrollingObject: scrollingObjects)
    {
        scrollingObject->scrollDown();
    }
    if(destructableObject != NULL)
    {
        destructableObject->scrollDown();
    }

    posY += Model::ScrollAmount;

    if(posY >= Model::SceneHeight)
    {
        this->setFinished(true);
    }
}
