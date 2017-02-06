//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_MODEL_H
#define AP_PROJECT_MODEL_H


class Player;
class Map;
class Bullet;

class Model {
    Map* map;
    Player* player;
    Bullet* bullet;
    bool paused;

public:
    static const int SceneWidth = 1000;
    static const int SceneHeight = 1000;
    static const int ScrollAmount = 2;

    void start();
    void pause();
    void resume();

    bool isPaused() const;
    void setPaused(bool paused);

    Model();
};


#endif //AP_PROJECT_MODEL_H
