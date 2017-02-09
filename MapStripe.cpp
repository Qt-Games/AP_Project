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


MapStripe::MapStripe(Model* model, DestructableObject *destructableObject, int sideBankWidth, int centerBankWidth, int posY, bool isBridge)
        : model(model), destructableObject(destructableObject), sideBankWidth(sideBankWidth), centerBankWidth(centerBankWidth) {

    finished = false;
    this->posY = posY;
    int x;
    int y;

    if(isBridge)
    {
        Road* leftSideRoad = new Road(0, posY, sideBankWidth, MapStripe::height);
        addToScrollingObjects(leftSideRoad);

        Road* rightSideRoad = new Road(Model::SceneWidth - sideBankWidth, posY, sideBankWidth, MapStripe::height);
        addToScrollingObjects(rightSideRoad);
    }
    else
    {
        x = 0;
        y = posY;
        Grass* leftSideGrass = new Grass(x, y, sideBankWidth, MapStripe::height+ 5);
        std::cout << "left side grass from 0 to " << sideBankWidth << endl;
        addToScrollingObjects(leftSideGrass);

        if(centerBankWidth != 0) {
            x = (Model::SceneWidth / 2) - centerBankWidth;
            y = posY;
            Grass *CenterGrass = new Grass(x, y, centerBankWidth * 2,MapStripe::height + 5);
            std::cout << "center grass from " << (Model::SceneWidth / 2) - centerBankWidth << " to ";
            std::cout <<  (Model::SceneWidth / 2) - centerBankWidth + centerBankWidth*2 << endl;
            addToScrollingObjects(CenterGrass);
        }

        x = Model::SceneWidth - sideBankWidth;
        y = posY;
        Grass* rightSideGrass = new Grass(x, y, sideBankWidth, MapStripe::height + 5);
        std::cout << "right side grass from " << Model::SceneWidth - sideBankWidth << " to ";
        std::cout << Model::SceneWidth << endl;
        addToScrollingObjects(rightSideGrass);

        std::cout << std::endl << std::endl;
    }

    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(advanceTime()));

    timer->start(20);
}


MapStripe::~MapStripe() {
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

void MapStripe::advanceTime() {
    if(model->isPaused()){
        return;
    }
    for(ScrollingObject* scrollingObject: scrollingObjects)
    {
        scrollingObject->scrollDown();
    }
    if(destructableObject != NULL)
    {
        destructableObject->scrollDown();
        destructableObject->move();
        if(!destructableObject->canPassThroughMapObjects())
        {
            int start = destructableObject->getPosX();
            int end = destructableObject->getPosX() + destructableObject->getSizeX();

            for(ScrollingObject* scrollingObject: scrollingObjects)
            {
                int scrollingStart = scrollingObject->getPosX();
                int scrollingEnd = scrollingObject->getPosX() + scrollingObject->getSizeX();

                if(start < scrollingEnd && end > scrollingStart)
                {
                    destructableObject->flip();
                }
            }
        }
    }
    posY += Model::ScrollAmount;

    if(posY >= Model::SceneHeight)
    {
        this->setFinished(true);
    }
}

