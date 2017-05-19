#ifndef LEVELOBJECTS_H
#define LEVELOBJECTS_H

#include <QObject>
#include <QGraphicsRectItem>

class LevelObjects: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    LevelObjects();
    bool isEnemy();
    bool isFood();
private:
    bool food;
    bool enemy;
public slots:
    void spawnFood();
    void spawnEnemy();
};

#endif // LEVELOBJECTS_H
