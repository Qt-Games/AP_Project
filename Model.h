//
// Created by dot_blue on 02/02/17.
//

#ifndef AP_PROJECT_MODEL_H
#define AP_PROJECT_MODEL_H


class MainWindow;
class Player;
class Map;
class Bullet;

class Model {
    Map* map;
    Player* player;
    Bullet* bullet;
    bool paused;
    MainWindow* mainWindow;

public:
    static const int SceneWidth = 1000;
    static const int SceneHeight = 1000;
    static const int ScrollAmount = 2;
    static const int FuelDecreaseRate = 1;

    void start();
    void pause();
    void resume();

    bool isPaused() const;
    void setPaused(bool paused);
    void setMainWindow(MainWindow *mainWindow);
    Player* getPlayer() const;

    Model();

    void advanceTime();
};


#endif //AP_PROJECT_MODEL_H
