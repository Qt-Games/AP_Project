#include "mainwindow.h"
#include <QApplication>

#include "Jet.h"
#include "Model.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;

int main(int argc, char *argv[])
{

    srand(time(0));
    Map* map = new Map();
    Player* player = new Player(Model::SceneWidth, 0, Direction::Right);

    Model model(map, player);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
