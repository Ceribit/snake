#include <QGraphicsScene>
#include <QTimer>
#include "player.h"

Player::Player(): xvelocity(10), yvelocity(0)
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Player::move()
{
    setPos(x()+xvelocity, y()+yvelocity);
    this->setFocus();
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Right && x() < scene()->width()){
        xvelocity = 10; yvelocity = 0;
    } else if(event->key() == Qt::Key_Left && x() > 0){
        xvelocity = -10; yvelocity = 0;
    } else if(event->key() == Qt::Key_Down&& x() < scene()->height() - this->rect().height()){
        xvelocity = 0; yvelocity = 10;
    } else if(event->key() == Qt::Key_Up&& x() > 0){
        xvelocity = 0; yvelocity = -10;
    }
}
