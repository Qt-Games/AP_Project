//
// Created by Y50 on 2/2/2017.
//

#include "GraphicScene.h"

QGraphicsScene* GraphicScene::instance = NULL;

QGraphicsScene *GraphicScene::getInstance() {
    if(instance == NULL)
    {
        instance = new QGraphicsScene();
        instance->setBackgroundBrush(QBrush(QColor(75, 100 , 255)));
    }
    return instance;
}

GraphicScene::~GraphicScene() {
    if(instance != NULL)
    {
        delete instance;
    }
}
