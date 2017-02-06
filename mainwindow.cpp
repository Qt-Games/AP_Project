#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGraphicsView>
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include "ui_mainwindow.h"
#include "playerplane.h"
#include <QString>
#include "GraphicScene.h"
#include "Model.h"
#include <sstream>
#include "Player.h"

MainWindow::MainWindow(Model* model, QWidget *parent) :
    model(model),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    model->setMainWindow(this);
    ui->setupUi(this);

    mainWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

    graphicsScene = GraphicScene::getInstance();
    graphicsView = new QGraphicsView(graphicsScene);
    graphicsView->setFixedSize(Model::SceneWidth, Model::SceneHeight);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsScene->setSceneRect(0 , 0 , Model::SceneWidth, Model::SceneHeight);
    mainLayout->addWidget(graphicsView);
    adjustSize();
    graphicsView->hide();

    playerInfoLayout = new QHBoxLayout();
    playerInfoWidget = new QWidget();
    playerInfoWidget->setLayout(playerInfoLayout);

    scoreLabel = new QLabel();
    scoreValue = new QLabel();
    scoreLabel->setText("Score:");
    scoreValue->setText("0");

    fuelGaugeLabel = new QLabel();
    fuelGaugeLabel->setText("       Remaining Fuel");
    fuelGauge = new QProgressBar();
    fuelGauge->setMinimum(0);
    fuelGauge->setMaximum(100);
    fuelGauge->setValue(100);

    scoreLabel->hide();
    scoreValue->hide();
    fuelGaugeLabel->hide();
    fuelGauge->hide();

    playerInfoLayout->addWidget(scoreLabel);
    playerInfoLayout->addWidget(scoreValue);
    playerInfoLayout->addWidget(fuelGaugeLabel);
    playerInfoLayout->addWidget(fuelGauge);

    mainLayout->addWidget(playerInfoWidget);

    startButton = new QPushButton();
    startButton->setText("Start Game !");
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    mainLayout->addWidget(startButton);






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

void MainWindow::updateView() {
    Player* player = model->getPlayer();
    fuelGauge->setValue(player->getFuelPercentage());

    std::stringstream ss;
    ss << player->getScore();
    scoreValue->setText(ss.str().c_str());
}






