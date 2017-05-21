#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include "player.h"
#include "snakeitem.h"

// Constructor
Player::Player(): xvelocity(10), yvelocity(0), head(nullptr)
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(20);
}

// Adds a tail
void Player::addTail()
{
    SnakeNode* node = head;
    if(node == nullptr){
        head = new SnakeNode();
        scene()->addItem(head);
        head->setRect(0, 0, 10, 10);
    } else{
    while(node->next != nullptr){node = node->next;}
    node->next = new SnakeNode();
    node->next->setRect(0, 0, 10, 10);
    scene()->addItem(node->next);
    }
}

// Move the tail following the player
void Player::updateTail()
{
 SnakeNode* node = head;
 if(head != nullptr){
     updateTailEnd(node);
     head->setPos(x()+scene()->width()/2, y()+ scene()->height()/2);
 }
}

// Recursively move the tail following the player
void Player::updateTailEnd(SnakeNode * node)
{
    if(node->next != nullptr){
        updateTailEnd(node->next);
        node->next->setPos(node->x(), node->y());
    }
}

void Player::checkCollisions()
{
    // Check Collision with enemies
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*colliding_items[i]) == typeid (SnakeItem)){
            if(static_cast<SnakeItem*>(colliding_items[i])->isFood()){
               scene()->removeItem(colliding_items[i]);
               delete colliding_items[i];
               addTail();
            } else{
                // Lose the game
            }
        }
    }
}

void Player::outOfBounds()
{
    // Move the character back in bounds if they attempt to go out
    if(x() > scene()->width()/2 - this->rect().width()){
        setPos(-scene()->width()/2, y()+yvelocity);
    } else if( y() > scene()->height()/2 - this->rect().height()){
        setPos(x(), -scene()->height()/2);
    } else if( x() < -scene()->width()/2){
        setPos(scene()->width()/2, y()+yvelocity);
    } else if( y() < -scene()->height()/2){
        setPos(x(), scene()->height()/2);
    }
}

void Player::move()
{
    //qDebug() << "Pos" << x() << ":" << y();

    // Move the player back in the board if they exit
    outOfBounds();

    // Check if the player ate a food or hit an enemy
    checkCollisions();

    // Move Tail
    updateTail();

    // Move player
    setPos(x()+xvelocity, y()+yvelocity);
    this->setFocus();
}

// Change direction if the player presses an arrow key
void Player::keyPressEvent(QKeyEvent* event)
{
    qDebug() << event->key() << " pressed.";
    if(event->key() == Qt::Key_Right && xvelocity == 0){
        xvelocity = 10; yvelocity = 0;
    } else if(event->key() == Qt::Key_Left && xvelocity == 0){
        xvelocity = -10; yvelocity = 0;
    } else if(event->key() == Qt::Key_Down && yvelocity == 0){
        xvelocity = 0; yvelocity = 10;
    } else if(event->key() == Qt::Key_Up && yvelocity == 0){
        xvelocity = 0; yvelocity = -10;
    }
}
