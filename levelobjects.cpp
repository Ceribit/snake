#include <QTimer>
#include <QGraphicsScene>
#include "levelobjects.h"
#include "snakeitem.h"
#include "gameview.h"

extern GameView* game;
LevelObjects::LevelObjects()
{
    QTimer *foodTimer = new QTimer(), *enemyTimer = new QTimer();
    QObject::connect(foodTimer, SIGNAL(timeout()), this, SLOT(spawnFood()));
    foodTimer->start(1000);
    QObject::connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    enemyTimer->start(7500);
}

bool LevelObjects::isEnemy()
{
    return enemy;
}

bool LevelObjects::isFood()
{
    return food;
}

void LevelObjects::spawnFood()
{
    SnakeItem* food = new SnakeItem(true);
    game->scene->addItem(food);
}

void LevelObjects::spawnEnemy()
{
    SnakeItem* enemy = new SnakeItem(false);
    game->scene->addItem(enemy);
}
