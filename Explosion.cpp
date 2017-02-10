//
// Created by Y50 on 2/10/2017.
//

#include "Explosion.h"
//#include <QMediaPlayer>
#include "MapStripe.h"

Explosion::Explosion(int posX, int posY, int sizeX, int sizeY, MapStripe* mapStripe) :
        ScrollingObject(posX, posY, 0, Direction::Left), sizeX(sizeX), sizeY(sizeY), mapStripe(mapStripe),Done(false) {

    QString path(RES_PATH);
    path.append("/explosion_sheet.png");
    spritesheet = new QImage(path);

    this->setGraphicObject(new QGraphicsPixmapItem());
    this->getGraphicObject()->setPos(posX, posY);

    GraphicScene::getInstance()->addItem(this->getGraphicObject());

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceTime()));
    timer->start(20);

//    QString soundPath(RES_PATH);
//    soundPath.append("/explosion.mp3");
//    QMediaPlayer *player = new QMediaPlayer;
//    player->setMedia(QUrl::fromLocalFile(soundPath));
//    player->play();

    currentFrame = 0;
}

Explosion::~Explosion() {
    delete timer;
    delete spritesheet;
}

void Explosion::advanceTime() {
    int x = currentFrame % SpritesInRow;
    int y = currentFrame / SpritesInRow;

    QRect cropRect(
            x * Explosion::SpriteSize,
            y * Explosion::SpriteSize,
            Explosion::SpriteSize,
            Explosion::SpriteSize
    );

    QImage cropped = spritesheet->copy(cropRect);
    cropped = cropped.scaled(sizeX, sizeY);
    this->getGraphicObject()->setPixmap(QPixmap::fromImage(cropped));

    currentFrame ++;


    if(currentFrame == SpritesInRow * SpritesInColumn) {
        if (mapStripe != NULL)
            mapStripe->clearExplosion();

        Done = true;
    }
}

bool Explosion::isDone() {
    return Done;
}

int Explosion::getSizeX() {
    return sizeX;
}
int Explosion::getSizeY() {
    return sizeY;
}