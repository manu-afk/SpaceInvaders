#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <iostream>
#include "turret.h"
#include <iostream>

Enemy::Enemy(QString sprite)
{
    setPixmap(QPixmap(sprite));
    directionMove = 10;     //De base, l'enemy se déplace de 10 px vers la droite
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    frameNumber = 0;
    QTimer *otherTimer = new QTimer();
    connect(otherTimer, SIGNAL(timeout()), this, SLOT(displayNextFrame()));
    otherTimer->start(150);
}

void Enemy::move(){
    QList<QGraphicsItem*> collidingItemsList = this->collidingItems();
    foreach(QGraphicsItem *item, collidingItemsList){
        if(typeid(*item) == typeid (Turret) ){
            this->scene()->removeItem(item);
            delete item;
            //this->scene()->removeItem(this);
            //delete this
            emit touchTurret();
        }
    }

    bool isRemove = false;
    if(y() >= this->scene()->height()){ //Si il dépasse le bas de l'écran
        this->scene()->removeItem(this);
        isRemove = true;
        delete this;
    }
    if(!isRemove){
        if(x() <= 0){ //Si touche le bord de gauche
            directionMove = 10;
            this->setPos(x(), y()+30);
        }
        else if(x() >= this->scene()->width() - this->boundingRect().width()){
            directionMove = -10;
            this->setPos(x(), y()+30);
        }
        setPos(x()+directionMove, y());
    }
}

void Enemy::displayNextFrame(){
    QPixmap *spriteSheet = new QPixmap(":/spriteSheetInvaders.png");
    int largeurFrame = spriteSheet->width()/2;
    int hauteurFrame = spriteSheet->height()/3;
    QRect *myRect = new QRect(frameNumber, 0, largeurFrame, hauteurFrame);
    setPixmap(spriteSheet->copy(*myRect));
    frameNumber += largeurFrame;
   if(frameNumber >= spriteSheet->width()) frameNumber = 0;
}

Enemy::~Enemy(){
    emit killed(10);
}
