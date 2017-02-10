//
// Created by Y50 on 2/2/2017.
//

#include "GraphicScene.h"

QGraphicsScene* GraphicScene::instance = NULL;

QGraphicsScene *GraphicScene::getInstance() {
    if(instance == NULL)
    {
        instance = new QGraphicsScene();
    }
    return instance;
}

GraphicScene::~GraphicScene() {
    if(instance != NULL)
    {
        delete instance;
    }
}
