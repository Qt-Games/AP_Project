//
// Created by Y50 on 2/2/2017.
//

#ifndef AP_PROJECT_GRAPHICSCENE_H
#define AP_PROJECT_GRAPHICSCENE_H


#include <QtWidgets/QGraphicsScene>

class GraphicScene {
    static QGraphicsScene* instance;


public:
    static QGraphicsScene* getInstance()
    {
        if(instance == NULL)
        {
            instance = new QGraphicsScene();
        }
        return instance;
    }
};


#endif //AP_PROJECT_GRAPHICSCENE_H
