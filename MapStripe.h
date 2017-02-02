//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_MAPSTRIPE_H
#define AP_PROJECT_MAPSTRIPE_H


#include "DestructableObject.h"
#include <thread>
#include <vector>

using namespace std;

class MapStripe {
    DestructableObject* destructableObject;
    int sideBankWidth;
    int centerBankWidth;
    vector<ScrollingObject*> scrollingObjects;

    thread* handlerThread;
};


#endif //AP_PROJECT_MAPSTRIPE_H
