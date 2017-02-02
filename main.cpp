#include "mainwindow.h"
#include <QApplication>

#include "Jet.h"
#include "Model.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main(int argc, char *argv[])
{

    srand(time(0));
    Map* map = new Map();   
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
