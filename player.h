#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "SnakeNode.h"

class Player: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    Player();
    void keyPressEvent(QKeyEvent* event);
    void addTail();
    void updateTail();
    void updateTailEnd(SnakeNode*);
    void checkCollisions();
    void outOfBounds();
private:
    int xvelocity;
    int yvelocity;
    SnakeNode *head;

public slots:
    void move();
};

#endif // PLAYER_H
