//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_MAP_H
#define AP_PROJECT_MAP_H

#include <queue>
#include "MapStripe.h"

class MapStripe;

class Map : public QObject{

    Q_OBJECT

    std::queue<MapStripe*> mapStripes;
    QTimer* timer;

public:
    std::queue<MapStripe*> createRandomLevel(int hardness);
    void addLevel(std::queue<MapStripe*> level);
    Map();

    virtual ~Map() {
        delete timer;
    }

public slots:
    void advanceTime();
};


#endif //AP_PROJECT_MAP_H
