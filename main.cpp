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

    Model* model = new Model();

    QApplication a(argc, argv);
    MainWindow w(model);
    w.show();



    return a.exec();
}
