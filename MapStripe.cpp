//
// Created by Y50 on 2/2/2017.
//

#include "MapStripe.h"
#include "Grass.h"
#include "Model.h"
#include <iostream>


MapStripe::MapStripe(DestructableObject *destructableObject, int sideBankWidth, int centerBankWidth, int posY, bool isBridge)
        : destructableObject(destructableObject), sideBankWidth(sideBankWidth), centerBankWidth(centerBankWidth) {


    if(isBridge)
    {

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
}

void MapStripe::addToScrollingObjects(ScrollingObject *scrollingObject) {
    scrollingObjects.push_back(scrollingObject);
}
