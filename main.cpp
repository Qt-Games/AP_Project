#include "mainwindow.h"
#include <QApplication>

#include "Jet.h"
#include <thread>
#include <iostream>

void func1()
{
    for(int i=0;i<10;i++)
    {
        std::cout<<"thread is being runed!!!"<<std::endl;
    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::thread omid(func1);
    omid.join();
    return a.exec();
}
