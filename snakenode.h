#ifndef SNAKENODE_H
#define SNAKENODE_H

#include <QGraphicsRectItem>

struct SnakeNode: public QGraphicsRectItem
{
public:
    SnakeNode* next;
    SnakeNode();
};

inline SnakeNode::SnakeNode():next(nullptr){}

#endif // SNAKENODE_H
