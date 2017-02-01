#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGraphicsView>
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include "ui_mainwindow.h"
#include "playerplane.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

    graphicsScene = new QGraphicsScene();
    PlayerPlane* player = new PlayerPlane();
    player->setPos(350 , 480);
    graphicsScene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();



    graphicsView = new QGraphicsView(graphicsScene);
    graphicsView->setFixedSize(800, 600);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsScene->setSceneRect(0 , 0 , 800, 600);
    mainLayout->addWidget(graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
