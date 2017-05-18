#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsObject>

#include "player.h"

class GameView: public QGraphicsView
{
public:
    //Constructor
    GameView();

    //Game variables
    QGraphicsScene* scene;
    Player* player;

};

#endif // GAMEVIEW_H
