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
    int lastMove;

public:
    static const int SceneWidth = 800;
    static const int SceneHeight = 1000;
    static const int BaseScrollAmount = 4;
    static const int MinScrollAmount = 1;
    static const int MaxScrollAmount = 7;
    static int ScrollAmount;
    static const int FuelDecreaseRate = 1;

    void start();

    void upKeyPressed();
    void downKeyPressed();
    void upKeyReleased();
    void downKeyReleased();

    bool isPaused() const;
    void setPaused(bool paused);
    void setMainWindow(MainWindow *mainWindow);
    Player* getPlayer() const;
    void gameOver();
    Model();

    void advanceTime();
};



#endif //AP_PROJECT_MODEL_H
