#ifndef FOOD_H
#define FOOD_H

#include <QObject>
#include <QGraphicsRectItem>

class SnakeItem: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    SnakeItem(bool);
    bool isFood();
    bool isEnemy();

private:
    bool food;
    bool enemy;
};

#endif // FOOD_H
