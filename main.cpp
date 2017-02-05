#include "mainwindow.h"
#include <QApplication>

#include "Jet.h"
#include "Model.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;

int main(int argc, char *argv[])
{

    srand(time(0));


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Map* map = new Map();
    Player* player = new Player(Model::SceneWidth, 0, Direction::Right);
    Model model(map, player);

    return a.exec();
}
