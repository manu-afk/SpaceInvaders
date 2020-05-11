#include "gameview.h"
#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <turret.h>
#include <enemy.h>
#include <iostream>
#include "score.h"
#include "ufo.h"
using namespace std;

GameView::GameView()
{
    nbEnnemies = 0;
    QGraphicsScene *myScene = new QGraphicsScene();
    myScene->setSceneRect(0, 0, 800, 600);
    QColor bgColor(0,0,0);
    myScene->setBackgroundBrush(bgColor);

    Turret *myTurret = new Turret(QString(":/tourelle.png"));
    myTurret->setPos(myScene->width()/2, myScene->height() - myTurret->boundingRect().height());
    myScene->addItem(myTurret);

    Score *myScore = new Score();
    myScene->addItem(myScore);

    for (int pos = 40; pos < myScene->width()-40; pos+=60){
            Enemy *myEnemy = new Enemy(QString(":/alien2.png"));
            myEnemy->setPos(pos , 20);
            QObject::connect(myEnemy, SIGNAL(killed(int)), myScore, SLOT(increaseScore(int)));
            QObject::connect(myEnemy, SIGNAL(killed(int)), this, SLOT(deathToll()));
            QObject::connect(myEnemy, SIGNAL(touchTurret()), this, SLOT(gameOver()));
            myScene->addItem(myEnemy);
            nbEnnemies ++;
    }
    for (int pos = 40; pos < myScene->width()-40; pos+=60){
            Enemy *myEnemy = new Enemy(QString(":/alien3.png"));
            myEnemy->setPos(pos , 80);
            QObject::connect(myEnemy, SIGNAL(killed(int)), myScore, SLOT(increaseScore(int)));
            QObject::connect(myEnemy, SIGNAL(killed(int)), this, SLOT(deathToll()));
            QObject::connect(myEnemy, SIGNAL(touchTurret()), this, SLOT(gameOver()));
            myScene->addItem(myEnemy);
            nbEnnemies ++;
    }

    Ufo *myUfo = new Ufo();
    QObject::connect(myUfo, SIGNAL(killed(int)), myScore, SLOT(increaseScore(int)));
    myScene->addItem(myUfo);

    setScene(myScene);
    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void GameView::deathToll(){
    nbEnnemies--;
    if(nbEnnemies == 0){
         QMessageBox message;
         message.setText("Victory");
         message.setIcon(QMessageBox::Information);
         message.exec();
    }
}

void GameView::gameOver(){
    QMessageBox message;
    message.setText("Game over");
    message.setIcon(QMessageBox::Information);
    message.exec();
}
