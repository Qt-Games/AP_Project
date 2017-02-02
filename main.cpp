#include "mainwindow.h"
#include <QApplication>

#include "Jet.h"
#include "Model.h"
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Map* map = new Map();
    Model model();
    return a.exec();
}
