//
// Created by dot_blue on 02/02/17.
//

#include <cstdlib>
#include <iostream>
#include "Map.h"
#include "DestructableObject.h"
#include "FuelDepot.h"
#include "Model.h"
#include "MapStripe.h"
#include "Helicopter.h"
#include "Ship.h"
#include "Jet.h"
#include "Bridge.h"
#include "Player.h"
#include "GraphicScene.h"
#include "Bullet.h"

std::deque<MapStripe*> Map::createRandomLevel(int hardness) {

    int lastPresentStripePosY = 0;
    if(this->mapStripes.size() > 0) {
        lastPresentStripePosY = mapStripes.back()->getPosY() - Model::SceneHeight;
    }

    int k = 1;
    std::deque<MapStripe*> result;

    for(int i = 0; i < 3; i++)
    {
        int sideBank = (int)(0.2 * Model::SceneWidth);
        int startY = Model::SceneHeight - (k * MapStripe::height) + lastPresentStripePosY;
        MapStripe* tempMapStripe = new MapStripe(model, NULL, sideBank, 0, startY, false);
        result.push_back(tempMapStripe);
        k++;
    }

    for(int i = 0; i < 3; i++)
    {
        cout << " STAGE " << i << endl ;
        int length = 10 + rand() % 5;
        int sideBank = 10 * (rand() % 10 + 5) ;
        bool isThereCenterBank = (rand() % 3 == 0);

        int centerBank = 0;
        if(isThereCenterBank)
        {
            centerBank = 10 * (rand()  % 9 + 1) ;
        }

        cout << "side bank : " << sideBank << endl;
        cout << "center bank : " << centerBank << endl<< endl << endl;


        for (int j = 0; j < length; ++j) {

            bool isThereFuelDepot = (rand() % (hardness + 2) == 0);
            bool isThereEnemyObject = (rand() % 10 < hardness);
            DestructableObject* destructableObject = NULL;
            int enemyTypeRandom = 0;
            int sizeX = 0;
            int sizeY = 0;

            if(isThereFuelDepot || isThereEnemyObject)
            {
                if(isThereFuelDepot)
                {
                    sizeX = FuelDepot::sizeX;
                    cout << "there is Fuel Depot Here in this stripe" << endl;
                }
                else{
                    if(isThereEnemyObject)
                    {
                        enemyTypeRandom = rand() % 3;
                        switch(enemyTypeRandom)
                        {
                            case 0:
                                cout << "there is Helicopter Here in this stripe" << endl;
                                sizeX = Helicopter::sizeX;
                                sizeY = Helicopter::sizeY;
                                break;
                            case 1:
                                cout << "there is Ship Here in this stripe" << endl;
                                sizeX = Ship::sizeX;
                                sizeY = Ship::sizeY;
                                break;
                            case 2:
                                cout << "there is Jet Here in this stripe" << endl;
                                sizeX = Jet::sizeX;
                                sizeY = Jet::sizeY;
                                break;
                            default:
                                std::cout << "UnExpected Error Happened";
                                exit(0);
                        }
                    }
                }

                Direction direction;
                int directionRandom = rand() % 2;
                if(directionRandom == 1)    direction = Direction::Left;
                else    direction = Direction::Right;



                int sceneX = Model::SceneWidth;
                int xRandomMin;
                int xRandomMax;
                int x;

                if(!isThereCenterBank)
                {
                    xRandomMin = sideBank;
                    xRandomMax = sceneX - sizeX - sideBank;
                }
                else
                {
                    int whichSideRandom = rand() % 2;
                    if(whichSideRandom == 0)
                    {
                        xRandomMin = sideBank;
                        xRandomMax = (sceneX/2) - centerBank - sizeX;
                    }
                    else
                    {
                        xRandomMin = (sceneX/2) + centerBank;
                        xRandomMax = sceneX - sideBank - sizeX;
                    }
                }
                x = xRandomMin + rand() % (xRandomMax - xRandomMin);

                int startY = Model::SceneHeight - (k * MapStripe::height) + lastPresentStripePosY;
                startY += MapStripe::height / 2;
                startY -= sizeY / 2;

                if(isThereFuelDepot)
                {
                    destructableObject = new FuelDepot(x, startY , direction);
                }
                else
                {
                    if(isThereEnemyObject)
                    {
                        switch(enemyTypeRandom)
                        {
                            case 0:
                                destructableObject = new Helicopter(x, startY, direction);
                                break;
                            case 1:
                                destructableObject = new Ship(x, startY, direction);
                                break;
                            case 2:
                                destructableObject = new Jet(x, startY, direction);
                                break;
                            default:
                                break;
                        }
                    }
                }
                destructableObject->setPlayer(this->model->getPlayer());
                cout << "sizeX : " << sizeX << endl;
                cout << xRandomMin << "   to    " << xRandomMax << endl;
                cout << "destructable x : " << x << endl;
                cout << endl << endl;
            }
            else
            {
                cout << "empty stripe" << endl << endl;
            }
            int startY = Model::SceneHeight - (k * MapStripe::height) + lastPresentStripePosY;
            MapStripe* tempMapStripe = new MapStripe(model,destructableObject, sideBank, centerBank, startY, false);
            result.push_back(tempMapStripe);
            k++;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        int sideBank = (int)(0.2 * Model::SceneWidth);
        int startY = Model::SceneHeight - (k * MapStripe::height) + lastPresentStripePosY;
        MapStripe* tempMapStripe = new MapStripe(model,NULL, sideBank, 0, startY, false);
        result.push_back(tempMapStripe);
        k++;
    }

    int startY = Model::SceneHeight - (k * MapStripe::height) + lastPresentStripePosY;
    int sideBank = (int)(0.4 * Model::SceneWidth);
    int bridgeWidth = (int)(0.2 * Model::SceneWidth);
    DestructableObject* destructableObject = new Bridge(sideBank, startY, bridgeWidth, MapStripe::height);
    destructableObject->setPlayer(this->model->getPlayer());
    MapStripe* tempMapStripe = new MapStripe(model, destructableObject, sideBank, 0, startY, true);
    result.push_back(tempMapStripe);

    return result;
}

void Map::addLevel(std::deque<MapStripe*> level) {
    while(level.size())
    {
        mapStripes.push_back(level.front());
        level.pop_front();
    }
}

void Map::advanceTime() {
    if(model->isPaused())
    {
        return;
    }
    while(mapStripes.size() > 0)
    {
        MapStripe* last = mapStripes.front();
        if(last->isFinished())
        {
            mapStripes.pop_front();
            //delete last;
            trashStripes.push_back(last);
        }
        else
        {
            break;
        }
    }

    if(mapStripes.back()->getPosY() > (-2 * MapStripe::height))
    {
        if(currentHardness < 10)
        {
            currentHardness++;
        }
        std::deque<MapStripe*> tmp_level=createRandomLevel(currentHardness);
        addLevel(tmp_level);
        Bullet::level=tmp_level;
        cout<<"NEW_LEVEL ADDED!!!"<<endl;

        //deleting the useless mapstrips:
        for_each(trashStripes.begin(),trashStripes.end(),[](MapStripe* strp){
            delete strp;
        });
        trashStripes.clear();

    }
    model->advanceTime();
}


void Map::startTimer() {
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceTime()));
    timer->start(500);
}

Map::Map(Model* model) : model(model){
    currentHardness = 5;
}

void Map::startGame() {
    std::deque<MapStripe*> tmp_level=createRandomLevel(currentHardness);
    Bullet::level=tmp_level;
    addLevel(tmp_level);

    startTimer();
}
