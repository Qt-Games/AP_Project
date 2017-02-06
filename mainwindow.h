#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>
#include "Model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Model* model;

    QWidget* mainWidget;
    QLayout* mainLayout;
    QGraphicsView* graphicsView;
    QGraphicsScene* graphicsScene;
    QLayout* playerInfoLayout;
    QWidget* playerInfoWidget;
    QPushButton* startButton;
    QPushButton* settingButton;
    QLabel* fuelGaugeLabel;
    QProgressBar* fuelGauge;
    QLabel* scoreLabel;
    QLabel* scoreValue;

public:
    explicit MainWindow(Model* model,QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void startGame()
    {
        startButton->hide();

        graphicsView->show();
        scoreLabel->show();
        scoreValue->show();
        fuelGaugeLabel->show();
        fuelGauge->show();

        model->start();
    };
};

#endif // MAINWINDOW_H
