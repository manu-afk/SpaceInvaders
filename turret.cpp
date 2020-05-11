#include "turret.h"
#include <QGraphicsScene>
#include "laser.h"
#include <QUrl>
#include <QTimer>

extern bool laserOnScreen;

Turret::Turret(QString sprite)
{
    laserOnScreen = false;
    setPixmap(QPixmap(sprite));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    laserSound = new QMediaPlayer();
    laserSound->setMedia(QUrl("qrc:/Laser1.wav"));
    leftPressed = false;
    rightPressed = false;
    QTimer *myTimer = new QTimer();
    connect(myTimer, SIGNAL(timeout()), this, SLOT(manageMoveKeys()));
    myTimer->start(50);
}

void Turret::keyPressEvent(QKeyEvent *event)
{

        if(event->key() == Qt::Key_Left ){
            leftPressed = true;
        }
        else if(event->key() == Qt::Key_Right ){
            rightPressed = true;
        }
        else if(event->key() == Qt::Key_Space && !laserOnScreen){
            //laserOnScreen = true;
            Laser *newLaser = new Laser(this->pos().x()+this->boundingRect().width()/2-2, this->pos().y()-this->boundingRect().height()/2-1);
            this->scene()->addItem(newLaser);
            if(laserSound->state() == QMediaPlayer::StoppedState){
                laserSound->play();
            }
            else if(laserSound->state() == QMediaPlayer::PlayingState){
                laserSound->setPosition(0);
            }
        }
}

void Turret::keyReleaseEvent(QKeyEvent *event){
     if(event->key() == Qt::Key_Left){
         leftPressed = false;
     }
     else if(event->key() == Qt::Key_Right){
        rightPressed = false;
     }
}

void Turret::manageMoveKeys(){
    if(leftPressed && this->pos().x() > 0){
        this->setPos(this->pos().x()-10, this->pos().y());
    }
    else if(rightPressed && this->pos().x()+this->boundingRect().width() < this->scene()->width()){
        this->setPos(this->pos().x()+10, this->pos().y());
    }
}
