//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_MAPSTRIPE_H
#define AP_PROJECT_MAPSTRIPE_H


#include "DestructableObject.h"
#include "Model.h"
#include <thread>
#include <vector>

using namespace std;

class MapStripe {
    int posY;
    int sideBankWidth;
    int centerBankWidth;
    vector<ScrollingObject*> scrollingObjects;
    bool finished;
    DestructableObject* destructableObject;


public:
    static const int height = 20;

    MapStripe(DestructableObject *destructableObject, int sideBankWidth, int centerBankWidth, int posY, bool isBridge);
    void addToScrollingObjects(ScrollingObject* scrollingObject);
    int getPosY() const;
    void setPosY(int posY);
    bool isFinished() const;
    void setFinished(bool isFinished);

    void scrollDown();


    virtual ~MapStripe();
};




#endif //AP_PROJECT_MAPSTRIPE_H
