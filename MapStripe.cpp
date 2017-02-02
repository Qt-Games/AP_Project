//
// Created by Y50 on 2/2/2017.
//

#include "MapStripe.h"
#include "Grass.h"


MapStripe::MapStripe(DestructableObject *destructableObject, int sideBankWidth, int centerBankWidth)
        : destructableObject(destructableObject), sideBankWidth(sideBankWidth), centerBankWidth(centerBankWidth) {

}

void MapStripe::addToScrollingObjects(ScrollingObject *scrollingObject) {
    scrollingObjects.push_back(scrollingObject);
}
