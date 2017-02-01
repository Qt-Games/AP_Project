//
// Created by Y50 on 2/1/2017.
//

#ifndef AP_PROJECT_OBJECT_H
#define AP_PROJECT_OBJECT_H


enum class Direction{
    Right, Left
};

class Object {
    static int id_generator;

    int id;
    int posX;
    int posY;
    int speed;
    Direction direction;


public:
    Object(int posX, int posY, int speed, Direction direction) : posX(posX), posY(posY), speed(speed),
                                                                 direction(direction) {
        id_generator ++;
        id = id_generator;
    }


    int getPosX() const;
    int getPosY() const;
    int getSpeed() const;
    Direction getDirection() const;


    void setPosX(int posX);
    void setPosY(int posY);
    void setSpeed(int speed);
    void setDirection(Direction direction);
};


#endif //AP_PROJECT_OBJECT_H
