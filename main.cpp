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

    Model* model = new Model();

    return a.exec();
}
