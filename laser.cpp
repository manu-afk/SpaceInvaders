#include "laser.h"
#include <QBrush>
#include <QTimer>
#include <QGraphicsScene>
#include "enemy.h"
#include "ufo.h"
#include <iostream>
using namespace std;

extern bool laserOnScreen;

Laser::Laser(int posX, int posY)
{
    this->width = 4;
    this->height = 10;
    setRect(0, 0, width, height);
    setPos(posX, posY);
    setBrush(QBrush(Qt::green));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Laser::move(){
    QList<QGraphicsItem*> collidingItemsList = this->collidingItems();
    bool isDelete = false;
    foreach(QGraphicsItem *item, collidingItemsList){
        if(typeid(*item) == typeid (Enemy) || typeid(*item) == typeid (Ufo)){
            this->scene()->removeItem(item);
            this->scene()->removeItem(this);
            delete item;
            delete this;
            isDelete = true;
            laserOnScreen = false;
        }
    }
    if(!isDelete){
        setPos(x(), y()-10);
        if(y() <= 0) {
            this->scene()->removeItem(this);
            delete this;
            laserOnScreen = false;
        }
    }

}
