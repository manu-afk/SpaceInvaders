#ifndef GAMEVIEW_H
#define GAMEVIEW_H
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
#include <QMessageBox>
using namespace std;


class GameView : public QGraphicsView
{
    Q_OBJECT
    int nbEnnemies;
public:
    GameView();
private slots:
    void deathToll();
    void gameOver();
};

#endif // GAMEVIEW_H
