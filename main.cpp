#include "mainwindow.h"
#include <QApplication>

#include "Jet.h"
#include "Model.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{

    srand(time(0));
    Map* map = new Map();
    cout << "finished" << endl;
    while(map->mapStripes.size())
    {
        std::cout << "a stripe !!!" << std::endl;
        map->mapStripes.pop();
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
