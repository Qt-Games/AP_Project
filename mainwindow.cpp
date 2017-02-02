#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGraphicsView>
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include "ui_mainwindow.h"
#include "playerplane.h"
#include <QString>
#include "GraphicScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

    graphicsScene = GraphicScene::getInstance();
    PlayerPlane* player = new PlayerPlane();
    player->setPos(350 , 480);
    graphicsScene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    graphicsView = new QGraphicsView(graphicsScene);
    graphicsView->setFixedSize(1000, 1000);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsScene->setSceneRect(0 , 0 , 1000, 1000);
    mainLayout->addWidget(graphicsView);

//    QGraphicsPixmapItem* bridgepxmap=new QGraphicsPixmapItem();
//    QString tmpstr(RES_PATH);
//    tmpstr.append("/road.png");
//    QImage image(tmpstr);
//    image=image.scaled(100,500);
//    bridgepxmap->setPixmap(QPixmap::fromImage(image));
//    graphicsScene->addItem(bridgepxmap);



}

MainWindow::~MainWindow()
{
    delete ui;
}
