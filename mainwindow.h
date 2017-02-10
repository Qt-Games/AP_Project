#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>
#include <iostream>
#include "Model.h"
#include <QKeyEvent>

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
    QLabel* gameOverStatus;
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
    void updateView();
    void resetView(const char* status);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

public slots:
    void startGame();
};




#endif // MAINWINDOW_H
