#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsObject>

#include "player.h"
#include "levelobjects.h"

class GameView: public QGraphicsView
{
public:
    //Constructor
    GameView();

    //Game variables
    QGraphicsScene* scene;
    Player* player;
    LevelObjects* objects;
};

#endif // GAMEVIEW_H
