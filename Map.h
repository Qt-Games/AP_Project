//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_MAP_H
#define AP_PROJECT_MAP_H

#include <deque>
#include "MapStripe.h"

class MapStripe;

class Map : public QObject{

    Q_OBJECT

    int currentHardness;
    std::deque<MapStripe*> mapStripes;
    std::vector<MapStripe*> trashStripes1;
    std::vector<MapStripe*> trashStripes2;
    QTimer* timer;
    Model* model;

public:
    std::deque<MapStripe*> createRandomLevel(int hardness);
    void addLevel(std::deque<MapStripe*> level);
    Map(Model* model);
    void startGame();
    void startTimer();

    virtual ~Map() {
        delete timer;
    }

public slots:
    void advanceTime();
};




#endif //AP_PROJECT_MAP_H
